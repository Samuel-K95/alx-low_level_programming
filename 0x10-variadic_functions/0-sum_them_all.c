#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * sum_them_all - add parameteres of a function
 *
 * @n: count
 * Return: integer
 */

int sum_them_all(const unsigned int n, ...)
{
	unsigned int i, total;
	va_list arr;

	va_start(arr, n);

	if (n == 0)
		return (0);
	total = 0;
	for (i = 0; i < n; i++)
	{
		total += va_arg(arr, unsigned int);
	}

	va_end(arr);

	return (total);
}
