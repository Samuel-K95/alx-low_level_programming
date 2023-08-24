#include "lists.h"
#include <stdlib.h>
#include <string.h>

/**
 * add_node - adds node to the head
 *
 * @head: node to be added
 * @str: string part of node
 * Return: new node
 */

list_t *add_node(list_t **head, const char *str)
{
	list_t *first;
	unsigned int size = 0;


	first = malloc(sizeof(list_t));
	if (first == NULL)
	{
		free(first);
		return (NULL);
	}

	while (str[size] != '\0')
		size++;

	first->len = size;
	first->str = strdup(str);
	first->next = *head;
	*head = first;

	return (*head);
}
