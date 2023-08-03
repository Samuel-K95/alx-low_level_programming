#include "main.h"
#include <stdio.h>

int check(char *s, int b, int c);
int length(char *a);

/**
 * is_palindrome - checks if palindrom
 *
 * @s:string to be checked
 * Return: integer
 */

int is_palindrome(char *s)
{
	int size, first;

	if (*s == ' ')
	{
		return (1);
	}
	else
	{
		size = length(s);
		first = 0;
		return (check(s, size, first));
	}
}

/**
 * length - counts length of string
 *
 * @a: string whose length to be counted
 * Return: integer
 */

int length(char *a)
{
	if (*a == '\0')
	{
		return (0);
	}
	else
	{
		return (1 + length(a + 1));
	}
}

/**
 * check- cehcks for palindrom
 *
 * @s: string to be checked
 * @b: used for indexing
 * @c: used for initial indexer
 * Return: integer
 */

int check(char *s, int b, int c)
{
	if (c >= b - 1)
	{
		return (1);
	}
	else if (s[c] != s[b - 1])
	{
		return (0);
	}
	else
	{
		return (check(s, b - 1, c + 1));
	}
}
