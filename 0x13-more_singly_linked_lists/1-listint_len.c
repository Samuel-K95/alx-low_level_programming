#include "lists.h"

/**
 * listint_len - returns length of list
 *
 * @h: start of node
 * Return: size_t
 */

size_t listint_len(const listint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		count++;
		h = h->next;
	}

	return (count);
}
