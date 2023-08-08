#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * argstostr - argument to string
 * 
 * @ac: number of arguments
 * @av: arguments
 * Return: string
 */

char *argstostr(int ac, char **av)
{
	char *dup;
	int i, size, j, a;

	if (ac == 0 || av == NULL)
		return (NULL);

	size = 0;
	a = 0;
	for (i = 0; i < ac; i++)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			size++;
			j++;
		}
		size++;
	}

	size++;

	dup = malloc (sizeof(int*) * size);
	if (dup == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			dup[a] = av[i][j];
			j++;
			a++;
		}
		dup[a] = '\n';
		a++;
	}

	dup[a] = '\0';

	return (dup);
}
