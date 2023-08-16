#include <stdio.h>
#include <stdlib.h>

/**
 * main - driver finction
 *
 * @argc: number of atrributes
 * @argv: array of character
 * Return: 0 or 1
 */

int main(int argc, char *argv[])
{
	int i, num;
	char *store = (char *)main;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	num = atoi(argv[1]);

	if (num < 0)
	{
		printf("Error\n");
		exit(2);
	}

	for (i = 0; i < num; i++)
	{
		printf("%02hhx ", store[i]);

		if (i == num - 1)
		{
			putchar('\n');
			break;
		}
	}

	return (0);
}




