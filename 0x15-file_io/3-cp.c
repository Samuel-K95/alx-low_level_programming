#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * main - main function
 *
 * @argc: number of arguments
 * @argv: list of arguments
 * Return: exit status and 0 if success
 */
int main(int argc, char *argv[])
{
	int from, read_, dest, write_, i;
	char *size;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	from = open(argv[1], O_RDONLY);
	if (from == -1)
	{
		dprintf(STDERR_FILENO, "Error: can't read from file %s\n", argv[1]);
		exit(98);
	}

	size = malloc(sizeof(char) * 1024);
	if (size == NULL)
		return (0);
	read_ = read(from, size, 1024);
	if (read_ == -1)
	{
		dprintf(STDERR_FILENO, "Error: can't read from file %s\n", argv[1]);
		exit(98);
	}
	dest = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (dest == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
	for (i = 0; read_; i++)
	{
		write_ = write(dest, size, read_);
		if (write_ == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			exit(99);
		}
		read_ = read(from, size, 1024);
		dest = open(argv[2], O_WRONLY | O_APPEND);
		if (read_ == -1)
		{
			dprintf(STDERR_FILENO, "Error: can't read from file %s\n", argv[1]);
			exit(98);
		}
		if (dest == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			exit(99);
		}
	}

	free(size);
	close(from);
	close(dest);

	return (0);
}
