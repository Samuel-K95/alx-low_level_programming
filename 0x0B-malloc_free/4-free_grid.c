#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * free_grid - free occupied space
 *
 * @grid: memory to be disalloacted
 * @height: height of multidimensional grid
 * Return: Null
 */

void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
		free(grid[i]);

	free(grid);
}
