#include "main.h"

/**
 * flip_bits - flips bits
 *
 * @m: target  number
 * @n: num to be flipped
 * Return: unsigned int
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int track = 0;
	unsigned long int NorM;

	NorM = n ^ m;
	while (NorM != 0)
	{
		if (NorM & 1)
			track++;
		NorM >>= 1;
	}

	return (track);
}
