#include "main.h"

/**
 * cmd_check - function to if and where command exist.
 * (where command is defined)
 * @args: pointer to array of arguments generated from
 * the comd_tokenizer function
 *
 * Return: a new path or args[0]
 */
char *cmd_check(char **args)
{
	int i;
	char *new_Path;

	for (i = 0; i < strlen(args[0]); i++)
	{
		if (args[0][i] != '/')
		{
			/* A basic command directory */
			char new_args0[100] = "/bin/";

			strcat(new_args0, args[0]);
			int len = strlen(new_args0) + 1;

			new_Path = malloc(len);
			strcpy(new_Path, new_args0);

			return (new_Path);
		}
		else
		{
			free(new_Path);
			return (args[0]);
		}
	}
}
