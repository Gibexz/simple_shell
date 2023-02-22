#include "main.h"

/**
 * fork_process - handles the child and parent processes;
 * @process: process value (i.e. less < 1, 0 or greater > one)
 * @args: arguments in command
 * @argv: arguments to main function
 *
 * Return: Nothing
 */
void fork_process(pid_t process, char **args, char **argv)
{
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
}
