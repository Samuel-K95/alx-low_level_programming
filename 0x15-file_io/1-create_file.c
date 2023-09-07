#include "main.h"
#include <stdlib.h>

/**
 * create_file - creates file
 *
 * @filename: file to be created;
 * @text_content: content of text
 * Return: int
 */

int create_file(const char *filename, char *text_content)
{
	int file_ptr, file_write, curr;

	curr = 0;

	if (filename == NULL)
		return (-1);

	if (text_content == NULL)
		return (1);
	while (text_content[curr] != '\0')
		curr++;

	file_ptr = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);

	if (file_ptr == -1)
		return (-1);
	file_write = write(file_ptr, text_content, curr);

	if (file_write == -1)
		return (-1);

	close(file_ptr);

	return (1);
}
