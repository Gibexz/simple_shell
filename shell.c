#include "main.h"

/**
 *
 *
 *
 */
int main(int argc, char **argv)
{
	int status, i;
	/* for wait system call of the parent process */
	char *command, *cmd_Tokens;
	size_t buffsize = 0;
	pid_t process;
	char *args[1000];
	ssize_t input;

	command = malloc(sizeof(char) * buffsize);
	if(command == NULL)
	{
		perror("Error:");
		return (1);
	}

	do {
		if (isatty(0) == 1)
			printf("$ ");

		input = getline(&command, &buffsize, stdin);
		if (input == -1)
		{
			perror("Error:");
			return (1);
			free(command);
		}

		cmd_Tokens = strtok(command, " \n");
		args[0] = cmd_Tokens;

		if (strcmp(command, "exit") == 0)
			exit(0);
		
		i = 1;
		while(cmd_Tokens != NULL)
		{
			cmd_Tokens = strtok(NULL, " \n");
			args[i] = cmd_Tokens;
			i++;
		}

		process = fork();

		if(process < 0) /* if any error */
		{
			perror("Error:");
			return (1);
		}
		if(process == 0) /* if child process */
		{
			printf("%s", args[0]);
			if (execve(args[0], args, environ) == -1)
			{
				perror("Error:");
				return (0);
			}
		}
		else /* if parent process */
		{
			wait(&status);
			printf("Parent\n");
		}
	}while(true);
	return (0);
}
