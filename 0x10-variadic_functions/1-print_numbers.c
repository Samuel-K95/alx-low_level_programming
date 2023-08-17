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

	if (separator == NULL)
		separator = "";
	va_start(arr, n);
	for (i = 0; i < n; i++)
	{
		if (i == n - 1)
			printf("%u", va_arg(arr, unsigned int));
		else
			printf("%u%s", va_arg(arr, unsigned int), separator);
	}

	putchar('\n');

	va_end(arr);
}
