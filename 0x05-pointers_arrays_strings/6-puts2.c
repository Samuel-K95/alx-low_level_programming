#include "main.h"
#include <stdio.h>

/**
 * puts2 - prints even string
 * @str: string to be printed
 *
 * Return: void
 */
 
void puts2(char *str)
{
	int i = 0;

	while (*str != '\0')
	{
		if (i % 2 == 0)
			_putchar(*str);
		i++;
		str++;
	}
	_putchar('\n');
}
