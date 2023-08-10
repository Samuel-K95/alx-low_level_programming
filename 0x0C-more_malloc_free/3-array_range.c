#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * array_range - creates an array range
 *
 * @min: starting range
 * @max: ending range
 * Return: int
 */

int *array_range(int min, int max)
{
	int *array;
	int i, j;

	if (min > max)
		return (NULL);
	array = malloc(sizeof(int) * (max - min + 1));

	if (array == NULL)
		return (NULL);
	j = 0;

	for (i = min; i <= max; i++)
	{
		array[j] = i;
		j++;
	}

	return (array);
}
