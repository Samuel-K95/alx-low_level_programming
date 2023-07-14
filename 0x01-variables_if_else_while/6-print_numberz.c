#include <stdio.h>

/**
 * main - driver code
 * Description: print numbers from 1 to 10
 * Return: 0 to terminate code
 */

int main(void)
{
	int i, num, digit, reversed;

	for (i = 0; i < 10; i++)
	{
		putchar(i + '0');
	}
	putchar('\n');
	return (0);
}
