#include "main.h"


/**
 * _isupper - checks if character is upper case or lower
 * Description: checks for uppercase
 * @c: ascii value of character
 * Return: 1 if uppercase 0 if not.
 */
int _isupper(int c)
{
	if ((c >= 65) && (c <= 90))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
