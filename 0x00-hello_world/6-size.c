#include<stdio.h>

/**
 * main - driver code
 * Description: prints size of data types
 * Return: 0 to terminate the code
 */

int main(void)
{
	printf("Size of a char: %d byte(s)\n", sizeof(char));
	printf("Size of an int: %d byte(s)\n", (unsigned int)sizeof(int));
	printf("SIze of a long int: %d byte(s)\n", (unsigned int)sizeof(long int));
	printf("Size of a long long int: %d byte(s)\n", sizeof(long long int));
	printf("Size of a float: %d byte(s)\n", sizeof(float));
	return (0);
}
