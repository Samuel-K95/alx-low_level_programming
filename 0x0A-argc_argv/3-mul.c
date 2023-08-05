#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - driver fucntion
 * Description: multiplies two numbers
 * @argc: number of arguments
 * @argv: string of argumenrts
 * Return: 1 or 0
 */

int main(int argc, char *argv[])
{
	int first, second;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}
	else
	{
		first = atoi(argv[1]);
		second = atoi(argv[2]);
		printf("%d\n", first * second);
	}

	return (0);
}
