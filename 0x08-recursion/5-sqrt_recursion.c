#include "main.h"
#include <stdio.h>


int square_root(int i, int n);

/**
 * _sqrt_recursion - computs squareroot
 *
 * @n: sqare root to be computed
 * Return: integer
 */

int _sqrt_recursion(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	else
	{
		return (square_root(0, n));
	}
}


/**
 * square_root - actual square root
 * Description: sqare root calculation
 * @i: counter
 * @n: square root to be computed to
 * Return: integer
 */

int square_root(int i, int n)
{
	if (i * i > n)
	{
		return (-1);
	}
	else if (i * i == n)
	{
		return (i);
	}
	else
	{
		return (square_root(i + 1, n));
	}
}
