#include "dog.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _strlen - length of string
 *
 * @s: string to be measured
 * Return: integer
 */

int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;

	return (i);
}

/**
 * _strcpy - copy string 1 to string 2
 * Description: copy string
 * @s1: first string
 * @s2: second string
 * Return: sting
 */

char *_strcpy(char *s1, char *s2)
{
	int i, j;

	i = 0;
	while (s1[i] != '\0')
		i++;
	for (j = 0; j < i; j++)
		s2[j] = s1[j];
	s2[j] = '\0';
	return (s2);
}

/**
 * new_dog - copies dog to new_dog
 * Description: dog copying
 * @name: name of dog
 * @age: age of dog
 * @owner: owner of dog
 * Return: void
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dup;
	int name_len, owner_len;

	name_len = _strlen(name);
	owner_len = _strlen(owner);
	dup = malloc(sizeof(dog_t));
	if (dup == NULL)
		return (NULL);
	dup->name = malloc(sizeof(char) * (name_len + 1));
	if (dup->name == NULL)
	{
		free(dup);
		return (NULL);
	}
	dup->owner = malloc(sizeof(char) * (owner_len + 1));
	if (dup->owner == NULL)
	{
		free(dup->name);
		free(dup);
		return (NULL);
	}
	_strcpy(name, dup->name);
	_strcpy(owner, dup->owner);
	dup->age = age;

	return (dup);
}
