
#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_HISTORY_NO 5

int	main(void)
{
	char *prompt;
	char *line;
	int lineSize;
	int index;
	int history_no;
	HIST_ENTRY *history;

	//	prompt = getenv("PROMPT");
	prompt = "$> ";
	// printf("prompt desu: %s\n", prompt);
	line = NULL;
	lineSize = 0;
	index = 0;
	history_no = 0;
	history = NULL;
	//
	while (line = readline(prompt))
	{
		lineSize = strlen(line);
		// for (index = 0; index < lineSize; index++)
		// {
		// 	printf("line[%d]=%c, ", index, line[index]);
		// }
		if (line[0] != '\0')
			add_history(line);
		if (++history_no > MAX_HISTORY_NO)
		{
			history = remove_history(0);
			free(history);
		}
		free(line);
	}
	printf("\n");
	clear_history();
	line = readline(prompt);
	printf(" last input = [ %s ]\n", line);
	free(line);
	return (EXIT_SUCCESS);
}