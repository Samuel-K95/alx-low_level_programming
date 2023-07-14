#include<stdio.h>

/**
 * main - driver code
 * Description -reversed lower case alphabet
 * Return: 0 to terminate code
 */

int main(void)
{
	char i;

	for (i = 'z'; i >= 'a'; i--)
	{
		putchar(i);
	}
	putchar('\n');
	return (0);
}
