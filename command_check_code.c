#include "main.h"

/**
 * command_code_check - exit command code (with or without status)
 * @command: point to command
 * @args: pointer to arguments from tokenization of command
 * @argc: Nos of arguments to main
 * @argv: Arguments to main
 * Return: nothing
 */
void command_code_check(char *command, char **args, int argc, char **argv)
{
	if (_strcmp(args[0], "exit") == 0)
		exit_code(command, args);
	if (_strcmp(args[0], "setenv") == 0)
		_setenv(args, argc, argv);
	/*if (_strcmp(args[0], "env") == 0)*/
		/*print_env(args);*/
	if (_strcmp(args[0], "unsetenv") == 0)
		_unsetenv(args, argc, argv);
}
