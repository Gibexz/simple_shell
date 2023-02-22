#include "main.h"

/**
 * print_c - function to print a char
 * @ap: Valist ap
 *
 * Return: count- Number of byte
 */
int print_c(va_list ap)
{
	char c;

	c = (char)va_arg(ap, int);
	_putchar(c);

	return (1);
}
