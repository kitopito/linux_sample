
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
	pid_t ppid = getppid();
	printf("Child process: %d; Current parent is %d\n", getpid(), ppid);
	sleep(3);
	kill(ppid, SIGUSR1);
	sleep(1);
	printf("プロセス%dの養子になったナリ！\n", getppid());
	exit(0);
	return 0;
}