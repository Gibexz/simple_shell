#include <unistd.h>

/**
 * _putchar - function to print a char to standard
 * output
 * @c: char character
 *
 * Return: prints to standard output
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
