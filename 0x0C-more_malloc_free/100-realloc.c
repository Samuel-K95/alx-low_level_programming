#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _realloc - reallocates memory block
 *
 * @ptr : old pointer
 * @old_size: oldsize
 * @new_size: new size
 * Return: void
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *reall;
	char *old_ptr;
	unsigned int i, size;

	if (old_size == new_size)
		return (ptr);
	if (ptr == NULL)
		return (malloc(new_size));
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (old_size < new_size)
		size = old_size;
	else if (new_size < old_size)
		size = new_size;

	reall = malloc(sizeof(char) * new_size);
	if (reall == NULL)
		return (NULL);
	old_ptr = ptr;
	for (i = 0; i < size; i++)
	{
		reall[i] = old_ptr[i];
	}
	free(ptr);
	return (reall);
}
