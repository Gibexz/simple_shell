#include "main.h"

/**
 * _unsetenv - Function to unset/delete an enviromental Varaibles
 * @args: command arguments
 * @argc: Number of arguments to main(UNUSED)
 * @argv: argumenats to main
 *
 * Return: NOTHING
 */
void _unsetenv(char **args, int argc, char **argv)
{
	int i, count;
	char *check_env;

	count = 0;
	for (i = 0; args[i]; i++)
		count += 1;
	if (i != 2)
	{
		_puts("setenv: No Variable\n");
		main(argc, argv);
	}

	check_env = getenv(args[1]);
	if (check_env == NULL)
	{
		_printf("The Environment Variable %s is invalid\n", args[1]);
		main(argc, argv);
	}
	if (unsetenv(args[1]) != 0)
	{
		perror("unsetenv:");
		main(argc, argv);
	}
	main(argc, argv);
}

