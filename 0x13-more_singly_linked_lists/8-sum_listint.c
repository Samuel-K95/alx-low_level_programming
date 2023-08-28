#include "lists.h"
#include <stdlib.h>

/**
 * sum_listint - adds up elements in a list
 *
 * @head: start of node
 * Return: integer
 */

int sum_listint(listint_t *head)
{
	int total;

	if (head == NULL)
		return (0);
	total = 0;
	while (head != NULL)
	{
		total += (head->n);
		head = head->next;
	}
	return (total);
}
