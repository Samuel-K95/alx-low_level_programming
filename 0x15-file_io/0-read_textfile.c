#include "main.h"
#include <stdlib.h>

/**
 * read_testfile - reads text file
 *
 * @filename: file to read from
 * @letters: content to be writted
 * Return: ssize_t
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t file_open, file_read, file_write;
	char *pointer;

	file_open = open(filename, O_RDONLY);
	if (file_open == -1)
		return (0);
	pointer = malloc(sizeof(char) * letters);
	if (pointer == NULL)
		return (0);

	file_read = read(file_open, pointer, letters);
	file_write = write(STDOUT_FILENO, pointer, file_read);
	free(pointer);
	close(file_open);
	return (file_write);
}
