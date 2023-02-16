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
			char p_args0[100] = "/bin/";

			strcat(p_args0, args[0]);

			new_Path = malloc(strlen(p_args0) + 1);
			strcpy(new_Path, p_args0);

			return (new_Path);
		}
		else
			return (args[0]);
	}
}
