#include "main.h"
#include <stdio.h>

/**
 * puts_half - prints half of a string
 * @str: string to be printed
 *
 * Return: void
 */

void puts_half(char *str)
{
	int i, start, j;

	j = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		j++;
	}

	if (j % 2 == 0)
	{
		start = j / 2;
	}
	else
	{
		start = ((j - 1) / 2);
	}

	for (i = start + 1; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}
