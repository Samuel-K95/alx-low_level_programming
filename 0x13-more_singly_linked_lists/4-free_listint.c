#include "lists.h"
#include <stdlib.h>

/**
 * free_listint - frees node
 *
 * @head: start of node
 * Return: void
 */

void free_listint(listint_t *head)
{
	struct listint_s *t;


	while (head != NULL)
	{
		t = head->next;
		free(head);
		head = t;
	}

}
