#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _calloc - allocates memeory for an array
 *
 * @nmemb: array
 * @size: size of array
 * Return: Null
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *mem;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);
	mem = malloc(size * nmemb);
	if (mem == NULL)
		return (NULL);
	for (i = 0; i < nmemb * size; i++)
		mem[i] = 'O';
	return (mem);
}
