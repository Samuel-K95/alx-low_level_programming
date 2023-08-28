#include "lists.h"
#include <stdlib.h>

/**
 * delete_nodeint_at_index - deletes node
 *
 * @head: node to be deleted
 * @index: postition to be deleted
 * Return: 1 or -1
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int i = 0;
	listint_t *track, *front, *now;

	if (*head == NULL)
	{
		return (-1);
	}
	if (index == 0)
	{
		track = *head;
		*head = (*head)->next;
		free(track);
		return (1);
	}
	front = (*head)->next;
	for (; front != NULL; i++)
	{
		if (i == index - 2)
		{
			now = front->next;
			front->next = now->next;
			free(now);
			return (1);
		}
		front = front->next;
	}

	return (-1);
}

