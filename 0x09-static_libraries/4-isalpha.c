#include "main.h"

/**
 * _isalpha - hchecks for alphabets
 * @c: character to be checked
 * Return: 1 for alphabetic characters 0 for anythign else
 */

int _isalpha(int c)
{
	if ((c >= 65 && c <= 97) || (c >= 97 && c <= 122))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
