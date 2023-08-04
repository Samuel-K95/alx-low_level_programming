#include "main.h"
#include <stdio.h>

/**
 * _strspn - counts initial characters in s
 *
 * @s: String to be counted
 * @accept: intial characters
 * Return: unsigned int
 */

unsigned int _strspn(char *s, char *accept)
{
	unsigned int c;
	int i;

	c = 0;

	while (*s != '\0')
	{
		for (i = 0; accept[i] != '\0'; i++)
		{
			if (*s == accept[i])
			{
				c++;
				break;
			}
			else
			{
				if (accept[i + 1] == '\0')
				{
					return (c);
				}
			}
		}
		s++;
	}

	return (c);
}
