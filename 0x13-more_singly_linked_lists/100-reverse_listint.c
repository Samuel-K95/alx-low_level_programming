#include "lists.h"

/**
 * reverse_listint - revrse linked list
 *
 * @head: hea of linked list
 * Return: listint_t
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *previous, *current_node;

	previous = NULL;
	current_node = (*head);
	while (*head != NULL)
	{
		current_node = (*head)->next;
		(*head)->next = previous;
		previous = (*head);
		(*head) = current_node;
	}

	*head = previous;
	return (*head);
}

