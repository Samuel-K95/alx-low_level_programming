#include "main.h"
#include <stdio.h>

/**
 * print_diagonal - prints diagonal lines
 * Descriptions: prints it for a number of times
 * @n: the number of times the diagonal is printed
 * Return: nothing
 */

void print_diagonal(int n)
{
	int i, j;

	if (n > 0)
	{
		for (i = 0; i < (n); i++)
		{
			for (j = 0; j < i; j++)
			{
				_putchar(' ');
			}
			_putchar('\\');
			_putchar('\n');
		}
	}
	else
	{
		_putchar('\n');
	}
}
