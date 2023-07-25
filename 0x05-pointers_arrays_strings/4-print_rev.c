#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 * print_rev - print string in reverse
 * @s: string to be printed
 *
 * Return: nothing
 */

void print_rev(char *s)
{
	int size;

	size = strlen(s);

	while (size >= 0)
	{
		_putchar(*(s + size));
		size--;
	}
	_putchar('\n');
}
