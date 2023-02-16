#include "main.h"

/**
 *
 *
 *
 */
char *cmd_check(char **args)
{/*
	int i;
	char *new_Path;

	for (i = 0; i < strlen(args[0]); i++)
	{*/ /*
		if (args[0][i] != '/')
		{*/
		/*	char new_args0[100] = "/bin/"; */

		/*	strcat(new_args0, args[0]);

			new_Path = malloc(strlen(new_args0) + 1);
			strcpy(new_Path, new_args0);

			return (new_Path);
		}*//*
		else
		{
			free(new_Path);
			return (args[0]);
		}
	}*/


	int i;
	char *path = getenv("PATH");

	for (i = 0; i < strlen(args[0]; i++)
	{
		if (arg[0][i] != '/')
		{
			char *path_dir = strtok(path, ":");

			while (path_dir != NULL)
			{
				char *p_arg0 = malloc(strlen(path_dir) + strlen(args[0]) + 1);
				if (p_arg0 == NULL)
				{
					perror(argv[0])
					return(1);
				}
				sprintf (p_arg0, "%s/%s", path_dir, args[0]);
				if (access(p_arg0, X_OK) == 0)
				{
					return (p_arg0);
				}
				free(p_arg0);
				path_dir = strtok(NULL, ":");
			}

		}

	}


}
