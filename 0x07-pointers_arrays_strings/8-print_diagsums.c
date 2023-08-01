#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - diagonal sum
 * Description: digonall sum of matrix
 * @a: array
 * @size: size of array
 * Return: nothing
 */

void print_diagsums(int *a, int size)
{
	int first, second, i, count;

	first = 0;
	second  = 0;
	count = size - 1;

	for (i = 0; i < size; i++)
	{
		first += a[i * size + i];
		second += a[count * size + (size - 1 - count)];
		count--;
	}

	printf("%d, %d\n", first, second);
}
