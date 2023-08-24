#include "lists.h"
#include <stdlib.h>

/**
 * free_list - frees memory address
 *
 * @head: node
 * Return: void
 */

void free_list(list_t *head)
{
	list_t *ptr;
	int i;

	for (i = 0; head; i++)
	{
		ptr = head->next;
		free(head->str);
		free(head);
		head = ptr;
	}
}
