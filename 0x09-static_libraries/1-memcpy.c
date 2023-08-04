#include "main.h"
#include <stdio.h>

/**
 * _memcpy - copies bytes from src to dest
 *
 * @dest: memory location to be transferred to
 * @src: memory location to be transferred from
 * @n: number of bytes to be transfered
 * Return: dest
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	int i;

	for (i = 0; n > 0; i++)
	{
		dest[i] = src[i];
		n--;
	}

	return (dest);
}
