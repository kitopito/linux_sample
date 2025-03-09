
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int	main(void)
{
	char *args[3][3] = {//
						{"ls", "-l", NULL},
						//
						{"/bin/ls", "-l", NULL},
						//
						{"../../../../bin/ls", "-l", NULL}};
	for (int i = 0; i < 3; i++)
	{
		pid_t pid = fork();

		if (pid == -1)
		{
			// fork失敗
			perror("fork");
			exit(1);
		}
		else if (pid == 0)
		{
			// 子プロセスの場合
			printf("Child process: Executing 'ls -l' command\n");

			// execveを使って新しいプログラムを実行
			if (execve(args[i][0], args[i], NULL) == -1)
			{
				// execveが失敗した場合
				perror("execve");
				exit(1);
			}
		}
		else
		{
			// 親プロセスの場合
			// 親は子プロセスの終了を待つ
			int status;
			waitpid(pid, &status, 0);
			printf("Parent process: Child process has finished\n");
		}
	}
}