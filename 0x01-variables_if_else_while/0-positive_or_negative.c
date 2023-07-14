#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/**
 * main - driver function
 * Description: checks if number is postive, negative or 0
 * Return: returns 0 to terminate the code
 */

int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;

	if (n > 2)
	{
		printf("%d is positive\n", n);
	}
	else if (n == 0)
	{
		printf("%d is zero\n", n);
	}
	else if (n < 0)
	{
		printf("%d is negative\n", n);
	}

	return (0);
}

