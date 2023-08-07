#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * alloc_grid - allocate grid
 *
 * @width: width of rectanlge
 * @height: height of rectangle
 * Return: int
 */

int **alloc_grid(int width, int height)
{
	int **grid;
	int i, j;

	if (width <= 0 || height <= 0)
		return (NULL);
	grid = (int **)malloc(sizeof(int *) * width);
	if (grid == NULL)
		return (NULL);

	for (i = 0; i < width; i++)
	{
		grid[i] =(int *)malloc(sizeof(int) * height);
		if (grid[i] == NULL)
			return (NULL);
	}

	for (i = 0; i < width; i++)
		for (j = 0; j < height; j++)
			grid[i][j] = 0;

	return (grid);
}
