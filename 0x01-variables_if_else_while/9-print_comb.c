#include <stdio.h>

/**
 * main - driver code
 * Description: comma separated numbers
 * Return: 0 to terminate program
 */

int main(void)
{
	int i;

	for (i = 0; i < 10; i++)
	{
		putchar(i + '0');
		if (i != 9)
		{
			putchar(',');
			putchar(' ');
		}
	}

	putchar('\n');
	return (0);
}
