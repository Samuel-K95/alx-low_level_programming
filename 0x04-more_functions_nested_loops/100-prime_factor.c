#include "main.h"
#include <stdio.h>

/**
 * main - prints prime factors of 1231952
 * Description: prime factorizartion
 * Return: 0 to terminate code
 */

int main(void)
{
	int i, large;
	long int n;

	n = 612852475143;

	while (n % 2 == 0)
	{
		n /= 2;
	}
	while (n % 3 == 0)
	{
		n /= 3;
	}
	for (i = 5;   i <= n; i++)
	{
		if (n % i == 0)
		{
			large = i;
			while (n % i == 0)
			{
				n /= i;
			}
		}
	}
	printf("%d", large);
	putchar('\n');

	return (0);
}
