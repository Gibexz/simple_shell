#include "main.h"

/**
 *
 *
 *
 *
 */
char *_strtok(char *str, const char *delim)
{
	char *start, *end;
	static char *last_str = NULL;

	if (str != NULL)
		last_str = str;
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
