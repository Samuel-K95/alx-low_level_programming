#include "main.h"

/**
 * set_bit: sets bit at a position
 *
 * @n: number in string format
 * @index: position
 * Return: 1 or -1
 */

 int set_bit(unsigned long int *n, unsigned int index)
{
	*n = ((1UL << index) | *n);

	return (index > 63 ? -1 : 1);
}
