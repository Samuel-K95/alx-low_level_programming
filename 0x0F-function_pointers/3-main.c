#include "3-calc.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * main - main function
 *
 * @argc: number of arguments
 * @argv: array
 * Return: 0 or 98 to exit code
 */

int main(int argc, char *argv[])
{
	int num1, num2;
	char *operator;

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}
	num1 = atoi(argv[1]);
	num2 = atoi(argv[3]);
	operator = argv[2];

	if (operator[1] != '\0' || get_op_func(operator) == NULL)
	{
		printf("Error\n");
		exit(98);
	}

	if ((operator[0] == '/' && num2 == 0) || (operator[0] == '%' && num2 == 0))
	{
		printf("Error\n");
		exit(98);
	}
	printf("%d\n", get_op_func(operator)(num1, num2));

	return (0);
}



