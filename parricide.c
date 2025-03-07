
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void	handler(int sig)
{
	write(STDERR_FILENO, "Et tu, Brute?\n", 14);
	exit(1);
}

// parrincide program
int	main(void)
{
	signal(SIGUSR1, handler);
	pid_t pid = fork();
	if (pid > 0)
	{
		// parent process
		printf("Parent process: %d\n", getpid());
		int status;
		wait(&status);
	}
	else if (pid == 0)
	{
		// child process
		pid_t ppid = getppid();
		printf("Child process: %d; Current parent is %d\n", getpid(), ppid);
		sleep(3);
		kill(ppid, SIGUSR1);
		sleep(1);
		printf("プロセス%dの養子になったナリ！\n", getppid());
		exit(0);
	}
	else
	{
		// error occurred
		perror("Fork");
		return (1);
	}
}