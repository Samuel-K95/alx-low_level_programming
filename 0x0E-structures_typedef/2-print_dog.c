#include "dog.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_dog - prints dog
 *
 * @d: dog
 * Return: void
 */

void print_dog(struct dog *d)
{
	if (d == NULL)
	{
	}
	else
	{
		if (d->name == NULL)
			d->name = "(nil)";
		if (d->owner == NULL)
			d->owner = "(nil)";
		printf("%s\n", d->name);
		printf("%f\n", d->age);
		printf("%s\n", d->owner);
	}
}
