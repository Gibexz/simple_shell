#include "main.h"

/**
 * exit_code_check - exit command code (with or without status)
 * @command: point to command
 * @args: pointer to arguments from tokenization of command
 *
 * Return: nothing
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
			int i;

			for (i = 0; i < strlen(args[1]); i++)
			{
				if ((args[1][i]) < 48 || (args[1][i]) < 57)
				{
					num = atoi(args[1]);
					free(args);
					free(command);
					exit(num);
				}
			}

		}
		else
		{
			perror("Error:");
		}
	}
}
