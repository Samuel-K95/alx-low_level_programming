#include "main.h"
#include <stdio.h>

/**
 * print_number - prints numbers
 * Description: prints numbers
 * @n: number to be printed
 * Return: nothing
 */

void print_number(int n)
{
	int rem, dup, dup1;

	dup = 0;
	rem = 0;
	dup1 = n;

	if (n == 0)
	{
		_putchar(n + '0');
	}

	else
	{
		if (dup1 < 0)
		{
			_putchar('-');
			n = n * -1;
		}
		while (n != 0)
		{
			rem = n  % 10;
			n = n / 10;
			dup = dup * 10 + rem;
		}

		while (dup != 0)
		{
			rem = dup % 10;
			dup  = dup / 10;
			_putchar(rem + '0');
		}
	}
}
