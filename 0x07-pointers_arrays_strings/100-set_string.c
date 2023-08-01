#include "main.h"
#include <stdio.h>

/**
 * set_string - setting string
 * Description: sets a value of a pointer to a char
 * @s: pointer
 * @to: char
 * Return: nothing
 */

void set_string(char **s, char *to)
{
	*s = to;
}
