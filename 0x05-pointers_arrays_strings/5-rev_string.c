#include "main.h"
#include <stdio.h>

/**
 * rev_string - reverses string
 * @s: string to be eversed
 *
 * Return: nothing
 */

void rev_string(char *s)
{
	char arr = s[0];
	int size = 0;
	int i;

	while (s[size] != '\0')
	{
		size++;
	}

	for (i = 0; i < size ; i++)
	{
		size--;
		arr = s[i];
		s[i] = s[size];
		s[size] = arr;
	}
}

