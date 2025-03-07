
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv, char **envp)
{
	// Print the environment variables
	size_t i;
	i = 0;
	printf("Environment Variables:\n");
	while (envp[i] != NULL)
	{
		printf("%s\n", envp[i]);
		i++;
	}

	// Print the command-line arguments
	printf("\nCommand-Line Arguments:\n");
	for (int i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}

	return (0);
}