#include "main.h"

/**
 * main - Entry point for simple shell c program
 * @argc: unused argc attribute; number of arguments to main
 * @argv: arguments to main
 *
 * Return: 0
 */
int main(int argc __attribute__((unused)), char **argv)
{
	int word_Count;
	char *command;
	char **args = NULL;
	size_t buffsize = 0;
	pid_t process;
	ssize_t input;

	command = malloc(sizeof(char) * buffsize);
	if (command == NULL)
	{
		perror(argv[0]);
		return (1);
	}
	while (1)
	{	/* Check if the input is associated with the command line terminal */
		if (isatty(0) == 1)
			printf("$ ");
		input = getline(&command, &buffsize, stdin);
		if (input == -1)
		{
			perror(argv[0]);
			free(command);
			return (1);
		}
		/* Generate the command and its arguments to be executed */
		args = tokens_array(command, &word_Count);
		exit_code_check(command, args);/* check for exit command */
		/* checks the nature of args[0], returns executable command if possible */
		args[0] = cmd_check(args);
		if (access(args[0], F_OK) != 0)/* checks if the args[0] is executable */
		{
			perror("Error:");
			return (1);
		}
		process = fork();/*create child and parent processes */
		/* Handles both child and perant processes */
		fork_process(process, word_Count, args, argv);
	}
	free(command);
	return (0);
}
