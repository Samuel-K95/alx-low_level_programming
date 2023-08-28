#include "lists.h"
#include <stdlib.h>

/**
 * insert_nodeint_at_index - adds node at index
 *
 * @head: node
 * @idx: index to be added
 * @n: node data
 * Return: listint_t
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *node_tba, *iter;
	unsigned int i;

	iter = *head;
	node_tba = malloc(sizeof(listint_t));
	if (node_tba == NULL || head == NULL)
		return (NULL);
	node_tba->n = n;

	if (idx == 0)
	{
		node_tba->next = *head;
		*head = node_tba;
		node_tba->next = NULL;
		return (node_tba);
	}
	for (i = 0; iter != NULL ; i++)
	{
		if (i == idx - 1)
		{
			node_tba->next = iter->next;
			iter->next = node_tba;
			return (node_tba);
		}
		iter = iter->next;
	}
	return (NULL);
}
