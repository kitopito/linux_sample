

#include <stdio.h>
#include <unistd.h>
int main(void) {
	int fd;
	while(fd != -1) {
		fd = dup(0);
		printf("%d\n", fd);
	}
	return 0;
}