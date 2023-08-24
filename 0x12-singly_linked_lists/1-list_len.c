#include "lists.h"

/**
 * list_len - return number of element
 *
 * @h: list
 * Return: size of linked list
 */

size_t list_len(const list_t *h)
{
	size_t n = 0;

	while (h != NULL)
	{
		n++;
		h = h->next;
	}

	return (n);
}
