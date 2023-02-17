#include "main.h"

/**
 *
 *
 *
 */
char *cmd_check(char **args)
{
/*	
	int i;
	char *new_Path;

	for (i = 0; i < strlen(args[0]); i++)
	{
		if (args[0][i] != '/')
		{
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
*/

	/****************************************************/
/*
	int i;
	char *path = getenv("PATH");
	char *p_arg0;
	char *path_dir = strtok(path, ":");

	for (i = 0; i < strlen(args[0]); i++)
	{
		if (args[0][i] != '/')
		{
			while (path_dir != NULL)
			{
				int len = strlen(path_dir) + strlen(args[0]) + 2;
				p_arg0 = realloc(p_arg0, len);
				if (p_arg0 == NULL)
				{
					perror("malloc:");
					exit(1);
				}
				char new_args0[100] = "";
				strcat(new_args0, path_dir);
				strcat(new_args0, "/");
				strcat(new_args0, args[0]);
				strcpy(p_arg0, new_args0);

				sprintf (p_arg0, "%s/%s", path_dir, args[0]);
				if (access(p_arg0, F_OK) == 0)
				{
					free(args[0]);
					memcpy(args[0], p_arg0, len); you can use string copy too 
					free(p_arg0);
					return (args[0]);
				}
				else
				{
					free(p_arg0);
				}
				path_dir = strtok(NULL, ":");
			}
		}
	}*/

	/**************************************************************/


	int k, path_count, len;
	char *new_path = NULL;

	for (k = 0; k < strlen(args[0]); k++)
	{
		if (args[0][k] != '/')
		{
			char *path = getenv("PATH");
			char *path_dir[100];
			int i = 0;

			char *token = strtok(path, ":");
			while (token != NULL)
			{
				path_dir[i] = token;
				printf("%s\n", token);
				i++;
				token = strtok(NULL, ":");
			}
			path_count = i;
			int j = 0;

			for (j = 0; j < path_count; j++)
			{
				free(new_path);
				len = strlen(path_dir[j]) + strlen(args[0]) + 2;
				new_path = malloc(len);
				if (new_path == NULL)
				{
					perror("malloc:");
					exit(1);
				}
				sprintf(new_path, "%s/%s", path_dir[k], args[0]);
				printf("New_path %s\n", new_path);
				if (access(new_path, F_OK) == 0)
				{
					return (new_path);
				}
			}

		}
		else
		{
			free(new_path);
			return (args[0]);
		}
	}
	free(new_path);
	return (NULL);
}
