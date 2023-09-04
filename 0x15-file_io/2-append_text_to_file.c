#include "main.h"
#include <stdlib.h>

/**
 * append_text_to_file - appends text to file
 *
 * @filename: file to be appended on
 * @text_content: text to be appended
 * Return: int
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int curr, write_file, file_open;

	if (filename == NULL)
		return (-1);

	curr = 0;

	if (text_content == NULL)
		return (1);
	while (text_content[curr] != '\0')
		curr++;
	file_open = open(filename, O_WRONLY | O_APPEND);
	write_file = write(file_open, text_content, curr);
	if (file_open == -1)
		return (-1);
	if (write_file == -1)
		return (-1);


	return (1);
}
