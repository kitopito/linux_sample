

#include <stdio.h>

// void	f(void)
// {
// 	printf("Hello, World!\n");
// 	return ;
// }
// void	hello(void)
// {
// 	int	a[1] = {0};

// 	//	int	*addr[1] = {0};
// 	// static int	i = 0;
// 	// i++;
// 	// printf("Hello, World! %p\n", hello);
// 	// printf("Hello, World! %p\n", addr);
// 	// printf("Hello, World! %p\n", &i);
// 	// addr[2] = &f;
// 	a[2] = &f;
// 	return ;
// }

// int	main(void)
// {
// 	hello();
// 	return (0);
// }
#include <stdio.h>

void	hack(void)
{
	printf("Hacked!\n");
}

void	func(void)
{
	int	*a[1];

	a[2] = hack;
}

int	main(void)
{
	func();
	return (0);
}