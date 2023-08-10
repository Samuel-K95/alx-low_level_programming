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
	size = i + n;


	concat = malloc(sizeof(char) * (size));

	if (concat == NULL)
		return (NULL);

	for (j = 0; s1[j]; j++)
		concat[j] = s1[j];
	for (j = 0; j < n; j++)
		concat[i + j] = s2[j];

	size += 1;
	concat[size] = '\0';


	return (concat);
}
