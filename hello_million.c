#include <stdio.h>

void	func(void)
{
	int	*a[1];

	printf("Hello, World!\n");
	a[2] = (int *)func;
	a[3] = (int *)func;
}

int	main(void)
{
	func();
	return (0);
}