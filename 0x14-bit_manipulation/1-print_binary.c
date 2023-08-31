#include "main.h"

/**
 * print_binary - prints binary form of a number
 *
 * @n: number
 * Return: void
 */

void print_binary(unsigned long int n)
{
	unsigned long int curr_num;
	int i, flag;

	i = 63;
	flag = 0;
	while (i >= 0)
	{
		curr_num = n >> i;

		if ((curr_num & 1) == 1)
		{
			_putchar('1');
			flag++;
		}
		else if (flag != 0)
			_putchar('0');
		i--;
	}
	if (flag == 0)
		_putchar('0');
}
