#include <stdio.h>
#include <ctype.h>

/**
 * main - driver code
 * Description: prints in lower format
 * Return: 0 to terminate code
 */

int main(void)
{
	char i;

	for (i = 'a'; i <= 'z'; i++)
	{
		putchar(i);
	}
	putchar('\n');

	return (0);
}
