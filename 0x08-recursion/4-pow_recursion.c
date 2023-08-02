#include "main.h"
#include <stdio.h>

/**
 * _pow_recursion - power of a number
 * Description: computes teh power of anumber
 * @x: number to be computed
 * @y: power to be raised to
 * Return: int
 */

int _pow_recursion(int x, int y)
{
	if (y < 0)
	{
		return (-1);
	}
	else if (y == 0)
	{
		return (1);
	}
	else
	{
		return (x * _pow_recursion(x, y - 1));
	}
}
