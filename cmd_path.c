#include "main.h"

/**
 *
 *
 *
 */
char *cmd_check(char **args)
{
	int i;
	char *new_Path;

	for (i = 0; i < strlen(args[0]); i++)
	{
		if (args[0][i] != '/')
		{
			char new_args0[100] = "/bin/";

			strcat(new_args0, args[0]);

			new_Path = malloc(strlen(new_args0) + 1);
			strcpy(new_Path, new_args0);

			return (new_Path);
		}
		else
			return (args[0]);
	}
}
