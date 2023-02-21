#include "main.h"

/**
 * main - Entry point for simple shell c program
 * @argc: unused argc attribute; number of arguments to main
 * @argv: arguments to main
 * 1 - Generate the command and its arguments to be executed
 * 2 - checks the nature of args[0], returns executable command if possible
 * 3 - Handles both child and perant processes
 * 4 -
 * Return: 0
 */
int main(int argc __attribute__((unused)), char **argv)
{
	int word_Count;
	char *command = NULL, **args = NULL, *dollar = "$ ";
	size_t buffsize = 1028;
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
			write(1, dollar, strlen(dollar));
		input = _getline(&command, &buffsize, stdin);
		if (input == -1)
		{
			perror(argv[0]);
			free(command);
			return (1);
		}
		args = tokens_array(command, &word_Count);/* 1 */
		command_code_check(command, args, argc, argv);/* check for exit command */
		args[0] = cmd_check(args);/* 2 */
		if (access(args[0], F_OK) == 0)/* checks if the args[0] is executable */
		{
			process = fork();/*creates child and parent processes */
			fork_process(process, word_Count, args, argv);/* 3 */
		}
		else
		{
			printf("%s: No such file or directoey\n", argv[0]);
			main(argc, argv);/* Recursion: calls the main funtion again*/
		}
	}
	free(command);
	return (0);
}
