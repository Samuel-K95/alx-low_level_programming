#include "main.h"
#include <stdlib.h>

/**
 * malloc_checked - allocates memory using malloc
 *
 * @b: memory to be allocated
 * Return: Null
 */

void *malloc_checked(unsigned int b)
{
	void *check;

	check = malloc(b);

	if (check == NULL)
	{
		exit(98);
	}
	return (check);
}
