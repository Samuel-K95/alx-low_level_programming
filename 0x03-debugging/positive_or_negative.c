#include "main.h"
#include <stdio.h>

/**
 * positive_or_negative - checks weather or not a number is positive
 * @n: number to be checked
 * Return: doesn't return anythin
 */

void positive_or_negative(int n)
{
	if (n < 0)
	{
		printf("%d is positive\n", n);
	}
	else if (n > 0)
	{
		printf("%d is negative\n", n);
	}
	else if (n == 0)
	{
		printf("%d is zero\n", n);
	}
}
