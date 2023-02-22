#include "main.h"

/**
 * print_deci - funtion to print integer (decimal)
 * @ap: va_list variable
 *
 * Return: count
 */
int print_deci(va_list ap)
{
	int digit[10]; /* array of numbers obtained from loop 1 */
	int i, count, sum_digit, num;
	int m = 1000000000;/* Divisor to be looped */

	num = va_arg(ap, int);
	count = 0;
	sum_digit = 0;


	for (i = 0; i < 10; i++)/* *Loop 1* */
	{
		digit[i] = (num / m) % 10;
		m /= 10;
	}

	if (num < 0)
	{
		_putchar('-');
		count++;
		for (i = 0; i < 10; i++)
		{/*loops throuh the array and multiply by -1 to make nums +ve */
			digit[i] = digit[i] * -1;
		}
	}


	for (i = 0; i < 10; i++)
	{
		sum_digit = sum_digit + digit[i];
		if (sum_digit != 0 || i == 9)
		{
			_putchar(digit[i] + '0');
			count++;
		}
	}
	return (count);
}


