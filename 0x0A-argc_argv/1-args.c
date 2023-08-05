#include "main.h"
#include <stdio.h>

/**
 * main - driver function
 * Description: prints number of arguments
 * @argc: number of arguments
 * @argv: arguments
 * Return: 0 to termiante function
 */

int main(int argc, char *argv[] __attribute__((unused)))
{
	printf("%d\n", argc - 1);

	return (0);
}
