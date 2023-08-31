#include "main.h"

/**
 * clear_bit - sets bit to 0
 *
 * @n: number
 * @index: position
 * Return: 1 or -1
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	*n = (~(1UL << index) & *n);

	return (index > 63 ? -1 : 1);
}
