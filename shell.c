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

	
	cmd_Tokens = strtok(cmd_input, " \n");

	i = 0;

	while (cmd_Tokens != NULL)
	{
		temp_args[i] = malloc(sizeof(char) * strlen(cmd_Tokens));

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
	int status, i;
	/* for wait system call of the parent process */
	char *command;
	size_t buffsize = 0;
	pid_t process;
	int word_Count;

	ssize_t input;

	command = malloc(sizeof(char) * buffsize);
	if(command == NULL)
	{
		perror("Error:");
		return (1);
	}

	do {
		/*isatty is used to determine if a given file descriptor refers to a terminal*/
		/*If 1 then it's a terminal*/
		if (isatty(0) == 1)
			printf("$ ");

		input = getline(&command, &buffsize, stdin);
		if (input == -1)
		{
			perror("Error:");
			return (1);
			free(command);
		}

		char **args = tokens_array(command, &word_Count);
		exit_command_check(args[0], args[1]);

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
			free(command);
			/* to free memory allocation for array of token(words) */
			for (i = 0; i < word_Count; i++)
				free(args[i]);
			free(args);
		}
	}while(true);
	return (0);
}
