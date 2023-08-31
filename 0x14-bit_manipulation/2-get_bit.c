#include "main.h"

/**
 * get_bit - returns bit at postition
 *
 * @n: number
 * @index: position
 * Return: bit
 */

int get_bit(unsigned long int n, unsigned int index)
{
	int target;

	target = n >> index;
	return (index > 63 ? -1 : (target & 1));
}
