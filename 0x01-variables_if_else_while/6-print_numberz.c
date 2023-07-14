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
		if (i == 0)
		{
			putchar('0');
		}
		else
		{
			num = i;
			while (num > 0)
			{
				digit = num % 10;
				reversed = reversed * 10 + digit;
				num /= 10;
			}
			while (reversed > 0)
			{
				digit = reversed % 10;
				putchar(digit + '0');
				reversed /= 10;
			}
		}
	}
	return (0);
}
