#include<stdio.h>

/**
 * main - driver code
 * Description: prints size of data types
 * Return: 0 to terminate the code
 */

int main(void)
{
	char c;
	int i;
	long int ln;
	long long int lln;
	float f;

	printf("Size of a char: %lu byte(s)\n", (unsigned long)sizeof(c));
	printf("Size of an int: %lu byte(s)\n", (unsigned int)sizeof(i));
	printf("SIze of a long int: %lu byte(s)\n", (unsigned int)sizeof(ln));
	printf("Size of a long long int: %lu byte(s)\n", (unsigned long)sizeof(lln));
	printf("Size of a float: %lu byte(s)\n", (unsigned long)sizeof(f));
	return (0);
}
