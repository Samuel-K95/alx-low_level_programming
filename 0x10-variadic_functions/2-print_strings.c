#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_strings - print strings
 *
 * @separator: char between string
 * @n: number of strings
 * Return: void
 */

void print_strings(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	char *word;
	va_list arr;

	va_start(arr, n);
	for (i = 0; i < n; i++)
	{
		word = va_arg(arr, char *);
		if (word == NULL)
			printf("(nil)");
		else
		{
			printf("%s", word);
		}

		if (i != (n - 1) && separator != NULL)
			printf("%s", separator);

	}

	printf("\n");

	va_end(arr);
}
