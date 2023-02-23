#include "main.h"

/**
 * print_s - function to print a string
 * @ap: valist ap
 *
 * Return: count - number of bytes printed
 */
int print_s(va_list ap)
{
	char *string;
	int i = 0;
	int count = 0;

	string = va_arg(ap, char*);
	if (string == NULL)
		string = "(null)";

	for (i = 0; string[i] != '\0'; i++)
	{
		_putchar(string[i]);
		count = count + 1;
	}
	return (count);
}
