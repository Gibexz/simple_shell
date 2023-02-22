#include "main.h"

/**
 * _setenv - Function to set enviromental Varaibles
 * @args: command arguments
 * @argc: Number of arguments to main(UNUSED)
 * @argv: argumenats to main
 *
 * Return: NOTHING
 */
void _setenv(char **args, int argc, char **argv)
{
	int i, count;

	count = 0;
	for (i = 0; args[i]; i++)
		count += 1;
	if (i != 3)
	{
		_puts("setenv: No Variable\n");
		main(argc, argv);
	/*	else if (args[2] == NULL)*/
	/*	{*/
	/*		if (getenv(args[1]) == NULL)*/
	/*		{*/
	/*			setenv(args[1], "", 1);*/
	/*		}*/
	/*	}*/
	}
	if (setenv(args[1], args[2], 1) != 0)
	{
		perror("setenv:");
	}
	main(argc, argv);
}

