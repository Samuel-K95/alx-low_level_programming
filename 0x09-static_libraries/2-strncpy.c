#include "main.h"
#include <stdio.h>

/**
 * _strncpy -  copy string
 * Description: copy string
 * @dest: string to be copied on
 * @src: string to be copied
 * @n: number of times to be copied
 * Return: String
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	for (i = i; i < n; i++)
	{
		dest[i] = '\0';
	}

	return (dest);
}
