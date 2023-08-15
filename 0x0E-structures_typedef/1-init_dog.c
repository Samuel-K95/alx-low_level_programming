#include "dog.h"
#include <stdio.h>
#include <stdio.h>

/**
 * init_dog - initializzes god
 * @d: dog
 * @name: name of dog
 * @age:age of dog
 * @owner: owner of dog
 * Return: void
 */

void init_dog(struct dog *d, char *name, float age, char *owner)
{
	struct dog *a;

	a = d;
	if (a == NULL)
		a = malloc(sizeof(struct dog));
	a->name = name;
	a->age = age;
	a->owner = owner;
}
