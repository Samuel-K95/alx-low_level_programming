#include "main.h"
#include <stdio.h>

/**
 * _strcat - concatenates two strings
 * Description: String concatenation
 * @dest: string to be added on
 * @src: string to be added
 * Return: String
 */

char *_strcat(char *dest, char *src)
{
	int d, s;

	d = 0;
	s = 0;

	while (dest[d] != '\0')
	{
		d++;
	}

	while (src[s] != '\0')
	{
		dest[d] = src[s];
		d++;
		s++;
	}

	dest[d] = '\0';

	return (dest);
}
