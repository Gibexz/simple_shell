#include "main.h"

/**
 * fork_process - handles the child and parent processes;
 * @process: process value (i.e. less < 1, 0 or greater > one)
 * @word_Count: number of arguments in command
 * @args: arguments in command
 * @argv: arguments to main function
 *
 * Return: Nothing
 */
void fork_process(pid_t process, char **args, char **argv)
{
	/*int status, j;*/

	if (process < 0) /* if any error */
	{
		perror("Error:");
	}
	if (process == 0) /* if child process */
	{
		/*printf("Child process\n");*/
		if (execve(args[0], args, environ) == -1)
		{
			perror(argv[0]);
		}
	}
	/*else  if parent process */
	/*{*/
	/*	wait(&status);*/
	/*	if (args != NULL)*/
	/*	{ *to free memory allocation for array of token(words)*/
	/*		for (j = 1; j < word_Count; j++)*/
	/*			free(args[j]);*/
	/*		free(args);*/
	/*	}*/
	/*}*/
}
