#include "main.h"
#include <stdio.h>

/**
 * swap_int - swaps two integers
 * Description: changes the values of two integers
 * @a: first number to be swapped
 * @b: second number to be swapped
 * Return: null
 */

void swap_int(int *a, int *b)
{
	int x;

	x = *b;
	*b = *a;
	*a = x;
}
