#include <stdio.h>

/**
 * main - driver code
 * Description: lower alphabets except q and e
 * Return: 0 to terminate code
 */

int main(void)
{
	char i;

	for (i = 'a'; i <= 'z'; i++)
	{
		if (i != 'q' && i != 'e')
		{
			putchar(i);
		}
	}
	putchar('\n');
	return (0);
}
