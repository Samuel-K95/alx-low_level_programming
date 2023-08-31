#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * binary_to_uint - converts binary to unsigned integer
 *
 * @b: binary rep of num
 * Return: unsigned integer
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int j, i, mult, pos, sum = 0;

	i = 0;
	while (b[i] != '\0')
		i++;
	j = 0;
	while (i > 0)
	{
		if (b[j] == '1')
		{
			mult = 1;
			for (pos = 0; pos < i - 1; pos++)
				mult *= 2;
			sum += mult;
		}
		else if (b[j] != '0')
			return (0);
		i--;
		j++;
	}
	return (sum);
}
