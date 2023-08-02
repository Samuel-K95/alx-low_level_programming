#include "main.h"
#include <stdio.h>

/**
 * factorial - computes factorial
 * Description: computing factorial of a number recurssively
 * @n: number whose factorial to be calculated
 * Return: integer
 */

int factorial(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	else if (n == 0)
	{
		return (1);
	}
	else
	{
		return (n * factorial(n - 1));
	}
}
