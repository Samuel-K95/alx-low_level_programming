#include "lists.h"
#include <stdlib.h>

/**
 * add_nodeint_end - adds node in the end
 *
 * @head: node to be added
 * @n: node data
 * Return: listint_t
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *end, *cop;

	cop = *head;
	end = malloc(sizeof(listint_t));
	if (end == NULL)
		return (NULL);
	end->n = n;
	end->next = NULL;

	if (*head == NULL)
	{
		*head = end;
		return (end);
	}

	while (cop->next != NULL)
		cop = cop->next;

	cop->next = end;

	return (end);
}
