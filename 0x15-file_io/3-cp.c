#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void check_close(int i);
void check_read(char *i);
void check_write(char *i);

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
		check_read(argv[1]);
	size = malloc(sizeof(char) * 1024);
	if (size == NULL)
		return (0);
	read_ = read(from, size, 1024);
	if (read_ == -1)
		check_read(argv[1]);
	dest = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (dest == -1)
		check_write(argv[2]);
	for (i = 0; read_; i++)
	{
		write_ = write(dest, size, read_);
		if (write_ == -1)
			check_write(argv[2]);
		read_ = read(from, size, 1024);
		dest = open(argv[2], O_WRONLY | O_APPEND);
		if (read_ == -1)
			check_read(argv[1]);
		if (dest == -1)
			check_write(argv[2]);
	}
	free(size);
	i = close(from);
	if (i == -1)
		check_close(i);
	read_ = close(dest);
	if (read_ == -1)
		check_close(read_);

	return (0);
}

/**
 * check_write - write checker
 *
 * @i: number to be checked
 * Return: exit status
 */
void check_write(char *i)
{
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", i);
	exit(99);
}

/**
 * check_read - read checker
 *
 * @i: number to be checked
 * Return: exit status
 */

void check_read(char *i)
{
	dprintf(STDERR_FILENO, "Error: can't read from file %s\n", i);
	exit(98);
}
/**
 * check_close - checks close
 *
 * @i: number to be checked
 * Return: exit status
 */

void check_close(int i)
{
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", i);
	exit(100);
}

