#include "main.h"
#include <stdio.h>

/**
 * more_numbers - prinitng more numbers
 * Description: 1 upto 14 10 times
 * Return: nothing
 */

void more_numbers(void)
{
	int i, j;

	j = 0;
	while (j < 10)
	{
		for (i = 0; i < 15 ; i++)
		{
			if (i >= 10)
				_putchar('1');
			_putchar(i % 10 + '0');
		}
		_putchar('\n');
		j++;
	}
}
