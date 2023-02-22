#include "main.h"

/**
 * exit_code - exit code program for the shell
 * @command: command string
 * @args: command arguments passed
 *
 * Return: Nothing
 */
void exit_code(char *command, char **args)
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

		for (i = 0; i < _strlen(args[1]); i++)
		{
			if ((args[1][i]) < 48 || (args[1][i]) < 57)
			{
				num = _atoi(args[1]);
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
