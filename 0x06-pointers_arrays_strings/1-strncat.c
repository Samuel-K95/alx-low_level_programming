#include "main.h"
#include <stdio.h>

/**
 * _strncat - concatenate two strings
 * Description: string concatenation
 * @dest: string to be added on
 * @char: string to be added
 * @n: number of bytes
 * Return: string
 */

char *_strncat(char *dest, char *src, int n)
{
	int d, s;

	d = 0;
	s = 0;

	while (dest[d] != '\0')
	{
		d++;
	}

	while (s < n && src[s] != '\0')
	{
		dest[d] = src[s];
		s++;
		d++;
	}

	dest[d] = '\0';

	return (dest);
}
