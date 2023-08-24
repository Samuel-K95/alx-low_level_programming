#include "lists.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/**
 * add_node_end - adds node at the end
 *
 * @head: node to be added
 * @str: string
 * Return: list_t
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *last;
	list_t *new;
	unsigned int size, i;

	new = *head;
	last = malloc(sizeof(list_t));

	if (last == NULL)
		return (NULL);

	size = 0;
	for (i = 0; str[size]; i++)
		size++;

	last->len = size;
	last->str = strdup(str);
	last->next = NULL;

	if (*head == NULL)
	{
		*head = last;
		return (last);
	}
	while (new->next != NULL)
		new = new->next;

	new->next = last;

	return (last);
}
