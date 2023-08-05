#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - driver function
 * Description: adds argv elements
 * @argc: number of elements
 * @argv: string of elements
 * Return: 0 or 1
 */

int main(int argc, char *argv[])
{
	int sum, i;

	if (argc < 1)
	{
		printf("%d\n", 0);
		return (0);
	}

	for (i = 1; i < argc; i++)
	{
		if (atoi(argv[i]))
		{
			sum += atoi(argv[i]);
		}
		else
		{
			printf("Error\n");
			return (1);
		}
	}

	printf("%d\n", sum);
	return (0);
}
