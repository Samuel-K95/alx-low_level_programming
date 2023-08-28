#include "lists.h"
#include <stdlib.h>

/**
 * add_nodeint - adds node at the beginning
 *
 * @head: node to  be added
 * @n: integer
 * Return: listint_t
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *front;

	front = malloc(sizeof(listint_t));
	front->n = n;
	front->next = *head;

	*head = front;

	return (front);
}
