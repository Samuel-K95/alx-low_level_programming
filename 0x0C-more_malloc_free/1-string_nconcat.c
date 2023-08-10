#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - concatenate string
 *
 * @s1: first string
 * @s2:second string
 * @n: length of s2;
 * Return: String
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *concat;
	unsigned int i, j, size, len2, len1;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	i = 0;
	while (s1[i] != '\0')
		len1++;
	j = 0;
	while (s2[j] != '\0')
		len2++;
	if (n < len2)
		size = len1 + n + 1;
	else
		size = len1 + len2 + 1;
	concat = malloc(sizeof(char) * (size));
	if (concat == NULL)
		return (NULL);
	j = 0;
	while (j < len1)
	{
		concat[j] = s1[j];
		j++;
	}
	i = 0;
	while (j < (len1 + n)  && n < len2)
	{
		concat[j] = s2[i];
		i++;
		j++;
	}
	while (n >= len2 && j < (len1 + len2))
	{
		concat[j++] = s2[i++];
	}
	concat[j] = '\0';
	return (concat);
}
