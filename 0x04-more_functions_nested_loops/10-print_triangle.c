#include "main.h"
#include <stdio.h>


/**
 * print_triangle - print triangle
 * Description: print trianlge for specified amount of time
 * @size: size of tiangle
 * Return: nothing
 */

void print_triangle(int size)
{
	if (size > 0)
	{
		int i, j;

		for (i = 1; i <= size; i++)
		{
			for (j = i; j < size; j++)
			{
				_putchar(' ');
			}

			for (j = 1; j <= i; j++)
			{
				_putchar('#');
			}

			_putchar('\n');
		}
	}
	else
	{
		_putchar('\n');
	}
}
