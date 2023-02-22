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
	int word_Count, status, j;
	size_t buffsize = 1028;
	char *command = malloc(sizeof(char) * buffsize), **args = NULL, *temp;
	pid_t process;
	static int num;

	while (1)
	{	/* Check if the input is associated with the command line terminal */
		if (isatty(0) == 1)
			_puts("$ ");/*write(1, dollar, strlen(dollar));*/
		num++;
		getline(&command, &buffsize, stdin);
		args = tokens_array(command, &word_Count);/* 1 */
		command_code_check(command, args, argc, argv);/* check for exit command */
		temp = args[0];
		args[0] = cmd_check(args);/* 2 */
		if (access(args[0], F_OK) == 0)/* checks if the args[0] is executable */
		{
			process = fork();/*creates child and parent processes */
			fork_process(process, args, argv);/* 3 */
			wait(&status);
			if (args != NULL)
			{
				for (j = 1; j < word_Count; j++)
					free(args[j]);
				free(args);
			}
			if (isatty(0) != 0)
				main(argc, argv);
		}
		else
		{
			_printf("%s: %d: %s: not found\n", argv[0], num, temp);
			if (isatty(0) != 1)
				break;
			main(argc, argv);/* Recursion: calls the main funtion again*/
		}
	}
	free(command);
	return (0);
}
