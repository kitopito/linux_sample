
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

#define POWER 10

int	main(void)
{
	pid_t	pid;

	for (int i = 0; i < POWER; i++)
	{
		pid = fork();
		if (pid != 0)
			waitpid(pid, NULL, 0);
	}
	printf("chu!\n");
	return (0);
}
