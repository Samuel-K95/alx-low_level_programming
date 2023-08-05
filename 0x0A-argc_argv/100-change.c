#include "main.h"
#include <stdio.h>
#include <stdlib.h>


/**
 * main - driver function
 * Description: print coin
 * @argc: number of arguments
 * @argv: string of arguments
 * Return: 0 or 1;
 */

int main(int argc, char *argv[])
{
	int cents, check;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	else
	{
		check = atoi(argv[1]);
		cents = 0;
		if (check < 0)
			printf("%d\n", 0);
		else
		{
			while (check != 0)
			{
				if (check >= 25)
					check -= 25;
				else if (check >= 10)
					check -= 10;
				else if (check >= 5)
					check -= 5;
				else if (check >= 2)
					check -= 2;
				else if (check >= 1)
					check -= 1;
				cents += 1;
			}
			printf("%d\n", cents);
		}
	}
	return (0);
}
