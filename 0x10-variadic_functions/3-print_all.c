#include <stdio.h>
#include "variadic_functions.h"
#include <stdarg.h>


/**
 * print_all - print any character
 *
 * @format: starting character
 * Return: void
 */
void print_all(const char * const format, ...)
{
	int i;
	va_list arr;
	char *word, *separation = "";

	va_start(arr, format);
	i = 0;
	if (format != NULL)
	{
		while (format[i])
		{
			switch (format[i])
			{
				case 'c':
					printf("%s%c", separation, va_arg(arr, int));
					break;
				case 'i':
					printf("%s%d", separation, va_arg(arr, int));
					break;
				case 'f':
					printf("%s%f", separation, va_arg(arr, double));
					break;
				case 's':
					word = va_arg(arr, char *);
					if (word == NULL)
						word = "(nil)";
					printf("%s%s", separation, word);
					break;
				default:
					i++;
					continue;
			}
			separation = ", ";
			i++;
		}
	}

	printf("\n");

	va_end(arr);
}
