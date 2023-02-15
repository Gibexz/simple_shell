#include "main.h"

/**
 *
 *
 *
 */
void exit_code_check(char *command, char **args)
{
	if (strcmp(args[0], "exit") == 0)
	{
		if (args[1] == NULL)
		{
			free(args);
			free(command);
			exit(0);
		}
		else if ((args[1] != NULL) && (args[2] == NULL))
		{
			int num;

			num = atoi(args[1]);
			free(args);
			free(command);
			exit(num);
		}
		else
		{
			perror("Error:");
		}
	}
}
