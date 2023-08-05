#include "main.h"
#include <stdio.h>

/**
 * main - driver function
 * Description: prints one argument at a time
 * @argc: number of argument
 * @argv: arguments
 * Return: 0 to terminate code
 */

int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
		printf("%s\n", argv[i]);

	return (0);
}
