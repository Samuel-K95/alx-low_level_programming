#include "main.h"
#include <stdio.h>

/**
 * _strstr - prints needele from haystack
 * Description: searching
 * @haystack: string to be searched from
 * @needle: string to be searched
 * Return: String
 */

char *_strstr(char *haystack, char *needle)
{
	while (*haystack != '\0')
	{
		char *first, *second;

		first = haystack;
		second = needle;

		while (*first == *second && *second != '\0')
		{
			first++;
			second++;
		}

		if (*second == '\0')
		{
			return (haystack);
		}

		haystack++;
	}

	return (0);
}
