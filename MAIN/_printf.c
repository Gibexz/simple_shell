#include "main.h"

/**
 * check_specifier - function pointer for check_spec
 * @format: characters after % i.e. c, s and %.
 * Return: function to run.
 */
int (*check_specifier(const char *format))(va_list)
{
	int i;

	print_struct p[5] = {
		{"c", print_c},
		{"s", print_s},
		{"i", print_int},
		{"d", print_deci},
		{NULL, NULL}
	};

	for (i = 0; i < 5; i++)
	{
		if ((*p[i].t) == *format)
			break;
	}
	return (p[i].funct);
}

/**
 * _printf - printf funtion for specifiers
 * @format: unknown variable types.
 * Return: count.
 */
int _printf(const char *format, ...)
{
	int i, count = 0;/* i for looping and count =  characters printed */
	int ret_count = 0; /* Value returned when check_specifier is call */
	va_list ap;
	int (*valist_funct_ptr)(va_list); /* funtion pointer */

	va_start(ap, format);
	if (format == NULL)/* check if format is a NULL pointer */
		return (-1);
	while (format[i])
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			count = count + 1;
			i++;
			continue;
		}
		if (format[i] == '%')
		{	/* funtion ptr assignment to checkspecifier */
			valist_funct_ptr = check_specifier(&format[i + 1]);
			if (valist_funct_ptr != NULL)
			{
				ret_count = valist_funct_ptr(ap);
				count = count + ret_count;
				i = i + 2; /* New index point i.e after the specifier characters */
				continue;
			}
			if (valist_funct_ptr == NULL)/* if the checkspecifier returns NULL */
				break;
			_putchar(format[i]);/* continue printing with the new index [i + 1] */
			count++;
			if (format[i + 1] == '%')
				i = i + 2;
			else
				i++;
		}
		i++;
	}
	va_end(ap);
	return (count);
}
