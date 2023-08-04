#include "main.h"
#include <stdio.h>

/**
 * _strcpy - copies string on another
 * @dest: string to be copied to
 * @src: string to be copied from
 * Return: string
 */



char *_strcpy(char *dest, char *src)
{
	int i;
	int x;

	x = 0;
	while (*(src + x) != '\0')
	{
		x++;
	}

	for (i = 0; i < x; i++)
	{
		dest[i] = src[i];
	}

	dest[x] = '\0';

	return (dest);
}
