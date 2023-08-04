#include "main.h"
#include <stdio.h>

/**
 * _isdigit - checks if digit or not
 * Description: digit or not
 * @c: character to be checked
 * Return: 1 if integer 0 if not
 */

int _isdigit(int c)
{
	if ((c >= 48) && (c <= 57))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
