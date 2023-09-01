#include "main.h"

/**
 * get_endianness - gets endianness
 *
 * Return: 1 or 0
 */

int get_endianness(void)
{
	unsigned int number = 1;

	return (*((char *)&number));
}
