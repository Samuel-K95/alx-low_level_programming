#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * print_list - prints all the elements of a list
 *
 * @h: list
 * Return: number of nodes
 */

size_t print_list(const list_t *h)
{
	size_t n = 0;

	while (h != NULL)
	{
		if (h->str == NULL)
		{
			printf("[0] (nil)\n");
			n++;
			h = h->next;
			continue;
		}
		printf("[%i] %s\n", h->len, h->str);
		h = h->next;
		n++;
	}

	return (n);
}
