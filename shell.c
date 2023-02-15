#include "main.h"



void exit_command_check(char *arg0, char *arg1)
{
	if ((strcmp(arg0, "exit") == 0) && (arg1 == NULL))
		exit(0);
}

char **tokens_array(char *cmd_input, int *word_Count)
{
	char *cmd_Tokens;
	char **temp_args;
	int i;

	temp_args = malloc(strlen(cmd_input) * sizeof(char*));
	if (temp_args == NULL)
	{
		perror("malloc:");
		exit(1);
	}

	
	cmd_Tokens = strtok(cmd_input, " \n");

	i = 0;

	while (cmd_Tokens != NULL)
	{
		temp_args[i] = malloc(sizeof(char) * strlen(cmd_Tokens) + 1);
		if (temp_args[i] == NULL)
		{
			perror("malloc:");
			exit(1);
		}

		strcpy(temp_args[i], cmd_Tokens);
		i++;
		cmd_Tokens = strtok(NULL, " \n");
	}

	*word_Count = i;
	return (temp_args);

}
/**
 *
 */
int main(int argc, char **argv)
{
	int status, i, j;
	/* for wait system call of the parent process */
	char *command;
	size_t buffsize = 0;
	pid_t process;
	int word_Count;

	ssize_t input;

	command = malloc(sizeof(char) * buffsize);
	if(command == NULL)
	{
		perror(argv[0]);
		return (1);
	}

	do {
		/* Check if the input is associated with the command line terminal */
		if (isatty(0) == 1)
			printf("$ ");

		/* */
		input = getline(&command, &buffsize, stdin);
		if (input == -1)
		{
			perror(argv[0]);
			free(command);
			return(1);
		}

		/* Generate the command and its arguments to be executed */
		char **args = tokens_array(command, &word_Count);
		/* check for exit command */
		exit_command_check(args[0], args[1]);

		for (i = 0; i < strlen(args[0]); i++)
		{
			if (args[0][i] == '/')
				break;
			else
			{
				/* get the PATH environment Variables */
				char *path = getenv("PATH");
				char *path_dir = strtok(path, ":");

				while (path_dir != NULL)
				{
					/*memory alloction for the full path to the command to become the new args[0]*/
					char *p_arg0 = malloc(strlen(path_dir) + strlen(args[0]) + 2);
					if (p_arg0 == NULL)
					{
						perror(argv[0]);
						return(1);
					}
					/* to construct the full path to the command */
					sprintf (p_arg0, "%s/%s", path_dir, args[0]);

					if (access(p_arg0, X_OK) == 0)
					{
						args[0] = p_arg0;
						break;
					}
					free(p_arg0);
				//	printf("%s\n", p_arg0);
					path_dir =strtok(NULL, ":");
				}
			}
		}
		process = fork();/*create child and parent processes */

		if(process < 0) /* if any error */
		{
			perror("Error:");
			return (1);
		}
		if(process == 0) /* if child process */
		{
			if (execve(args[0], args, environ) == -1)
			{
				perror(argv[0]);
				return (1);
			}
		}
		else /* if parent process */
		{
			wait(&status);
			sleep(4);
			free(command);
			/* to free memory allocation for array of token(words) */
			for (j = 1; i < word_Count; j++)
				free(args[j]);
			free(args);
		}
	}while(true);
	return (0);
}
