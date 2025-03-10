
#include <stdio.h>
#include <unistd.h>

#define POWER 3

int	main(void)
{
	for (int i = 0; i < POWER; i++)
	{
		fork();
	}
	printf("chu!\n");
	return (0);
}
