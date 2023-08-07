#include "main.h"
#include <stdio.h>
#include <stdlib.h>


/**
 * create_array - creates an array of chars
 *
 * @size: size of array
 * @c: character to intialzie
 * Return: string
 */
char *create_array(unsigned int size, char c)
{
	char *arr;
	unsigned int i;

	if (size == 0)
	{
		return (0);
	}
	else
	{
		arr = malloc(sizeof(char) * size);
		for (i = 0; i < size; i++)
		{
			arr[i] = c;
		}
	}

	return (arr);
}
