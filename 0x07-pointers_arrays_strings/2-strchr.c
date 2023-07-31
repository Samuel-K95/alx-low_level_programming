#include "main.h"
#include <stdio.h>

/**
 * _strchr - search for the first occurence of apecific character
 *
 * @s: string in which the character is searched
 * @c: character to be searched
 * Return: string
 */
char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == c)
		{
			return (&s[i]);
		}
	}

	return (0);
}
