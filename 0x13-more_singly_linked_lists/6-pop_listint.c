#include "lists.h"
#include <stdlib.h>

/**
 * pop_listint - removes head
 *
 * @head: linked list
 * Return: int
 */

int pop_listint(listint_t **head)
{
	int n;
	listint_t *store;

	if (*head == NULL)
		return (0);


	store = (*head)->next;
	n = (*head)->n;
	free(*head);
	*head = store;

	return (n);
}
