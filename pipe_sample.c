#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int pipe_fd[2];  // パイプ用のファイルディスクリプタ
    pid_t pid1, pid2;

    // パイプを作成
    if (pipe(pipe_fd) == -1) {
        perror("pipe");
        exit(1);
    }

    // 最初のプロセス（lsコマンド）を実行
    if ((pid1 = fork()) == 0) {
        // 子プロセスで標準出力をパイプの書き込み端に接続
        close(pipe_fd[0]);  // 読み取り端は閉じる
        dup2(pipe_fd[1], STDOUT_FILENO);  // 標準出力をパイプに接続
        close(pipe_fd[1]);  // 書き込み端は閉じる

        // execveを使ってlsコマンドを実行
        char *args[] = {"/bin/ls", NULL};
        if (execve(args[0], args, NULL) == -1) {
            perror("execve");
            exit(1);
        }
    }

    // 2番目のプロセス（grepコマンド）を実行
    if ((pid2 = fork()) == 0) {
        // 子プロセスで標準入力をパイプの読み取り端に接続
        close(pipe_fd[1]);  // 書き込み端は閉じる
        dup2(pipe_fd[0], STDIN_FILENO);  // 標準入力をパイプに接続
        close(pipe_fd[0]);  // 読み取り端は閉じる

        // execveを使ってgrepコマンドを実行
        char *args[] = {"/bin/grep", "test", NULL};  // "test"を含む行を検索
        if (execve(args[0], args, NULL) == -1) {
            perror("execve");
            exit(1);
        }
    }

    // 親プロセスでパイプを閉じ、子プロセスの終了を待つ
    close(pipe_fd[0]);
    close(pipe_fd[1]);
    waitpid(pid1, NULL, 0);  // 最初の子プロセスの終了を待機
    waitpid(pid2, NULL, 0);  // 2番目の子プロセスの終了を待機

    return 0;
}
