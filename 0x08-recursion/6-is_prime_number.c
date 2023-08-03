#include "main.h"
#include <stdio.h>


int prime_checker(int i, int n);

/**
 * is_prime_number - checks if numer is prime or not
 * description: prime checker
 * @n: number to be checked
 * Return: integer
 */

int is_prime_number(int n)
{
	if (n == 2 || n == 3)
	{
		return (1);
	}
	else if (n <= 1)
	{
		return (0);
	}
	return (prime_checker(2, n));
}

/**
 * prime_checker - actual prime checker
 * Description: checks if a number is prime or not recursively
 * @i: counter
 * @n: number to be checked
 * Return: integer
 */

int prime_checker(int i, int n)
{
	if (i * i > n)
	{
		return (1);
	}
	else if (n % i == 0)
	{
		return (0);
	}
	else
	{
		return (prime_checker(i + 1, n));
	}
}
