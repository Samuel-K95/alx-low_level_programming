#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_numbers - print numbers
 *
 * @separator: string to be printed between numbers
 * @n: amount of numbers
 * Return: void
 */

void print_numbers(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	va_list arr;

	va_start(arr, n);
	for (i = 0; i < n; i++)
	{
		printf("%d", va_arg(arr, unsigned int));
		if (separator != NULL && i != (n - 1))
			printf("%s", separator);
	}

	printf("\n");
	va_end(arr);
}
