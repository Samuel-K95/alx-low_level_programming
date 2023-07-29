#include "main.h"
#include <stdio.h>

/**
 * _strcmp - compare two strings
 * Description: string comparison
 * @s1: fist string to be compared
 * @s2: scond string to be compared
 * Return: integer
 */

int _strcmp(char *s1, char *s2)
{
	int s;

	s = 0;

	while (s1[s] != '\0' && s2[s] != '\0')
	{
		if (s1[s] != s2[s])
		{
			return (s1[s] - s2[s]);
		}

		s++;
	}

	return (0);
}
