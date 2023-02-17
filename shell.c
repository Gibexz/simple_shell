#include "main.h"

/**
 *
 *
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

	while(1)
	{
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
		exit_code_check(command, args);
		args[0] = cmd_check(args);
		if (access(args[0], F_OK) != 0)
		{
			perror("Error:");
			return(1);
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
			printf("Parent process\n");
			sleep(1);

			//to free memory allocation for array of token(words)
			for (j = 0; i < word_Count; j++)
				free(args[j]);
			free(args);
			//free(command);
		}
	}
	return (0);
}
