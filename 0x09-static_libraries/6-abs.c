#include "main.h"

/**
 * _abs - prints absolute value of a number
 * @c: The number to be computed
 * Return: Absolute value of a number or 0
 */

int _abs(int c)
{
	if (c < 0)
	{
		int abs_val;

		abs_val = c * -1;
		return (abs_val);
	}
	return (c);
}
