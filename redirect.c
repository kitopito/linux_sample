
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	int		fd;
	char	*filename;
	char	*command;
	char	**options;

	if (argc < 4)
	{
		fprintf(stderr, "Usage: %s <filename> r/rr <command (option)>\n",
			argv[0]);
		exit(EXIT_FAILURE);
	}
	// コマンドを実行する前にリダイレクトを行う
	filename = argv[1];
	command = argv[3];
	options = argv + 3;
	if (strcmp(argv[2], "r") == 0)
	{
		// 出力をファイルにリダイレクト
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
		{
			perror("open");
			exit(EXIT_FAILURE);
		}
		// 標準出力をリダイレクト先のファイルに接続
		if (dup2(fd, STDOUT_FILENO) == -1)
		{
			perror("dup2");
			exit(EXIT_FAILURE);
		}
		close(fd); // ファイルディスクリプタを閉じる
		// コマンドを実行（例: `echo` コマンド）
		execvp(command, options);
	}
	else if (strcmp(argv[2], "rr") == 0)
	{
		// 出力をファイルに追記
		fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (fd == -1)
		{
			perror("open");
			exit(EXIT_FAILURE);
		}
		// 標準出力をリダイレクト先のファイルに接続
		if (dup2(fd, STDOUT_FILENO) == -1)
		{
			perror("dup2");
			exit(EXIT_FAILURE);
		}
		close(fd); // ファイルディスクリプタを閉じる
		// コマンドを実行（例: `echo` コマンド）
		execvp(command, options);
	}
	else
	{
		fprintf(stderr, "Invalid operator: %s\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	return (0);
}
