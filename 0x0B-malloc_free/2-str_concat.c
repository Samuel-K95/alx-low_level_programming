#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * str_concat - concatenate two string
 *
 * @s1: first string
 * @s2: second string
 * Return: concatenated string
 */

char *str_concat(char *s1, char *s2)
{
	unsigned int i, count, l1, l2;
	char *dup;

	if (s1 == NULL || s2 == NULL)
	{
		return (NULL);
	}
	else
	{
		count = 0;
		i = 0;
		l1 = 0;
		l2 = 0;
		while (s1[i] != '\0')
		{
			count++;
			i++;
			l1++;
		}
		i = 0;
		while (s2[i] != '\0')
		{
			count++;
			i++;
			l2++;
		}

		count++;

		dup = malloc(sizeof(char) * count);

		for (i = 0; i < l1; i++)
			dup[i] = s1[i];
		for (i = 0; i < count; i++)
			dup[l1 + i] = s2[i];
	}

	return (dup);
}
