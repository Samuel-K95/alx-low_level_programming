#include "main.h"
#include <stdio.h>

/**
 * _memset - fills first n memory addresses with b
 *
 * @s: memory address
 * @b: caharacter to fill the memory
 * @n: number of memory addresses
 * Return: String
 */

char *_memset(char *s, char b, unsigned int n)
{
	int i;

	for (i = 0; n > 0; i++)
	{
		*s = b;
		s++;
		n--;
	}

	return (s);
}
