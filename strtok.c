#include "main.h"

/**
 * _strtok - string tokenizing function
 * @command: inputed string
 * @delim: string breaker character(s)
 *
 * Return: char pointers to strings
 */
char *_strtok(char *command, const char *delim)
{
	char *start, *end;
	static char *last_str;

	if (str != NULL)
		last_str = command;
	if (last_str == NULL)
		return (NULL);

	start = last_str;
	end = strpbrk(start, delim);
	if (end != NULL)
	{
		*end = '\0';
		last_str = end + 1;
	}
	else
		last_str = NULL;
	return (start);
}
