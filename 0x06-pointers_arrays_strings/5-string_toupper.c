#include "main.h"
#include <stdio.h>

/**
 * string_toupper - changes to upper
 *
 * @s: string to be changed to upper
 * Return: string
 */

char *string_toupper(char *s)
{
	int pos;

	pos = 0;

	while (s[pos] != '\0')
	{
		if (s[pos] >= 97 && s[pos] <= 122)
		{
			s[pos] = s[pos] - 32;
		}

		pos++;
	}
	return (s);
}
