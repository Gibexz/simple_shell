#include "main.h"

#define PATH_MAX 4096

/**
 * cmd_check - function to search for directory where the main
 * command is defined i.e. args[0].
 * @args: pointer to arguments.
 *
 * sprintf - function used for catenation of pointer and arrays;
 * Return: excutable path of function or just args[0]
 */
char *cmd_check(char **args)
{
	char *path_env = getenv("PATH");
	char *main_command  = args[0];

	if (args[0][0] == '/')
		return (main_command);

	char *path_tokens = strtok(path_env, ":");

	if(args[0][0] != '/')
	{
	while(path_tokens != NULL)
	{
		char executable_path[PATH_MAX];
		snprintf(executable_path, PATH_MAX, "%s/%s", path_tokens, args[0]);
		
		struct stat st;
		if (stat(executable_path, &st) == 0 && (st.st_mode & S_IXUSR))
			return strdup(executable_path);
		path_tokens = strtok(NULL,":");
	}
	}
	else
		return main_command;
}
