#include "main.h"
#include <stdio.h>

/**
 * print_line - prints _
 * Description: prints _ for a specified amount of time
 * @n: the number of times _ is printed
 * Return: nothing
 */

void print_line(int n)
{
	int i;

	if (n > 0)
	{
		for (i = 0; i < n; i++)
		{
			_putchar('_');
		}
	}
	_putchar('\n');
}
