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
		if (s1 == NULL)
			s1 = "";
		if (s2 == NULL)
			s2 = "";
		l1 = 0, l2 = 0, count = 0;
		while (s1[l1] != '\0')
		{
			l1++;
			count++;
		}
		while (s2[l2] != '\0')
		{
			l2++;
			count++;
		}
		dup = malloc(sizeof(char) * count + 1);
		if (dup == NULL)
			return (NULL);
		for (i = 0; i < l1; i++)
			dup[i] = s1[i];
		for (i = 0; i < count + 1; i++)
			dup[l1 + i] = s2[i];
	return (dup);
}
