#include "lists.h"
#include <stdlib.h>

/**
 * get_nodeint_at_index - gets node at speicific index
 *
 * @head: start of node
 * @index: position in linked list
 * Return: listint_t
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i;
	listint_t *target;

	target = malloc(sizeof(listint_t));
	if (target == NULL)
		return (NULL);
	for (i = 0; head != NULL; i++)
	{
		if (i == index)
		{
			target = head;
			return (target);
		}
		head = head->next;
	}
	free(target);

	return (NULL);
}
