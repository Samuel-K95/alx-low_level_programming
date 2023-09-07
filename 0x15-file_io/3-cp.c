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
	int from, read_, dest, write_;
	char *size;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	from = open(argv[1], O_RDONLY);

	size = malloc(sizeof(char) * 1024);

	read_ = read(from, size, 1024);
	dest = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	do {
		write_ = write(dest, size, read_);
		if (write_ == -1)
			printf("error");
		read_ = read(from, size, 1024);
		dest = open(argv[2], O_WRONLY | O_APPEND);
	} while (read_ > 0);

	free(size);
	close(from);
	close(dest);

	return (0);
}
