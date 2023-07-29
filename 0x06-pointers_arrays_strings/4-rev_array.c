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

	for (i = 0; a[i] != a[n - i - 1]; i++)
	{
		temp = a[i];
		a[i] = a[n - i - 1];
		a[n - i - 1] = temp;
	}

}
