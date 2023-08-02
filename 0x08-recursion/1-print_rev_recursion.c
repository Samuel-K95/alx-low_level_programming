#include "main.h"
#include <stdio.h>


/**
 * _print_rev_recursion - reverse recurrsion
 * Description: prints string in reverse
 * @s: string to be printed
 * Return: nothing
 */

void _print_rev_recursion(char *s)
{
	if (*s != '\0')
	{
		_print_rev_recursion(s + 1);
		_putchar(*s);
	}
}
