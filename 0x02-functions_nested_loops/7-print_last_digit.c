#include "main.h"

/**
 * print_last_digit - print the lsat digit
 * @n: the numbe to be treated
 * Return: Value of lsat digit number
 */

int print_last_digit(int n)
{
	int last;

	last = n % 10;
	if (last < 0)
	{
		last = last * -1;
	}
	_putchar(last + '0');
	return (last);
}
