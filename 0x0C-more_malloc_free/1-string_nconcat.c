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
	unsigned int i, j, size;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	i = 0;
	while (s1[i] != '\0')
		i++;
	j = 0;
	while (s2[j] != '\0')
		j++;
	if (n >= j)
		n = j;
	size = i + n + 1;


	concat = malloc(sizeof(char) * (size));

	if (concat == NULL)
		return (NULL);
	j = 0;
	while (j < i)
	{
		concat[j] = s1[j];
		j++;
	}
	i = 0;
	while (j < size)
	{
		concat[j] = s2[i];
		i++;
		j++;
	}
	concat[j] = '\0';


	return (concat);
}
