#include <stddef.h>
#include "function_pointers.h"
#include <stdio.h>

/**
 * array_iterator - iterates over an array
 *
 * @array: array
 * @action: action to be executed
 * @size: size of array
 * Return: void
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if (array == NULL || action == NULL)
		return;
	for (i = 0; i < size; i++)
		action(array[i]);
}
