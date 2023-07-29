#include "main.h"
#include <stdio.h>

/**
 * leet - encoding to 1337
 *
 * @str: string to be concoded
 * Return: string
 */

char *leet(char *str)
{
	int i, j;

	char wor[] = "aAeEoOtTlL";
	char val[] = "4433007711";

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (str[i] == wor[j])
			{
				str[i] = val[j];
			}
		}
	}
	return (str);
}
