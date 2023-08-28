#include "lists.h"
#include <stdlib.h>

/**
 * free_listint2 - free list and print nil
 *
 * @head: node to start fro
 * Return: void
 */

void free_listint2(listint_t **head)
{
	listint_t *store;

	if (*head == NULL)
		return;

		while ((*head) != NULL)
		{
			store = (*head)->next;
			free(*head);
			*head = store;
		}

		*head = NULL;
}
