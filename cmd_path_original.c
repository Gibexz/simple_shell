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
	char *new_Path = NULL;
		/*free(new_Path)*/
		if (args[0][0] != '/')
		{
			/* A basic command directory */
			char new_args0[100] = "/bin/";

			strcat(new_args0, args[0]);
			int len = strlen(new_args0) + 1;

			new_Path = malloc(len);
			if (new_Path == NULL)
			{
				perror("malloc:");
				exit(1);
			}
			strcpy(new_Path, new_args0);
			return (new_Path);
		}
		else
		{
			char new_args0[100] = "";

			strcat(new_args0, args[0]);
			int len = strlen(new_args0) + 1;

			new_Path = malloc(len);
			if (new_Path == NULL)
			{
				perror("malloc:");
				exit(1);
			}
			strcpy(new_Path, new_args0);
			return (new_Path);
		}
		return (NULL);
}
