#include "main.h"
#include <stdio.h>

/**
 * reverse_array - reverses array
 *
 * @a: array
 * @n: number of elements in a
 * Return: null
 */

void reverse_array(int *a, int n)
{
	int i, temp;

	for (i = 0; i < n--; i++)
	{
		temp = a[i];
		a[i] = a[n];
		a[n] = temp;
	}

}
