#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _strdup -copies string and returns its pointer
 *
 * @str: string to be copied
 * Return: string
 */

char *_strdup(char *str)
{
	char *dup;
	unsigned int i, count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		count++;
		i++;
	}
	count++;
	dup = malloc(sizeof(char) * count);
	if (str == 0 || dup == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < sizeof(char) * count; i++)
	{
		dup[i] = str[i];
	}

	return (dup);
}
