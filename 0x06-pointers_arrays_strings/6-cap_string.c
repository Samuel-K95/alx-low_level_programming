#include "main.h"
#include <stdio.h>

/**
 * cap_string - capitalizig
 *
 * @string: string to be capitalized
 * Return: string
 */

char *cap_string(char *string)
{
	int pos = 0;

	while (string[pos] != '\0')
	{
		while (!(string[pos] >= 'a' && string[pos] <= 'z'))
		{
			pos++;
		}
		if (string[pos - 1] == ' ' || string[pos -1] == '\t' || string[pos - 1] == '\n'|| string[pos - 1] == ',' || string[pos - 1] == ';' || string[pos - 1] == '.' || string[pos - 1] == '!' || string[pos - 1] == '?' || string[pos - 1]  == '"' || string[pos - 1] == '(' || string[pos - 1] == ')' || string[pos - 1] == '{' || string[pos - 1] == '}'|| pos == 0)
			string[pos] -= 32;
		pos ++;
	}


	return (string);
}
