#ifndef DOG_H
#define DOG_H
#include <stdio.h>
#include<stdlib.h>

/**
 * struct dog - dog struct
 * @name: name of dog
 * @age: age of dog
 * @owner: owner of dog
 *
 * Description: structure contains different attrivutes of a dog
 */

struct dog
{
	char *name;
	float age;
	char *owner;
};

#endif /* DOG_H */
