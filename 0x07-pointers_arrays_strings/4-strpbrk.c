#include "main.h"
#include <stdio.h>

/**
 * _strpbrk - searches for first occerence of any byte of accept in string
 *
 * @s: byte to be searched in
 * @accept: byte to be searched from
 * Retun: String
 */

char *_strpbrk(char *s, char *accept)
{
	int i;

	while (*s != '\0')
	{
		for (i = 0; accept[i] != '\0'; i++)
		{
			if (*s == accept[i])
			{
				return (s);
			}
		}

		s++;
	}

	return ('\0');
}
