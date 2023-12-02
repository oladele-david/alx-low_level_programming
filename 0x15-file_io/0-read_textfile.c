#include "main.h"
#include <stdlib.h>

/**
 *read_textfile - Reads a text file and prints it to POSIX stdout.
 *@filename: A pointer to the name of the file.
 *@letters: The number of letters the function should read and print.
 *
 *Return: If the function fails or filename is NULL - 0.
 *        O/w - the actual number of bytes the function can read and print.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t file_descriptor, read_result, write_result;
	char *buffer;

	if (filename == NULL)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
	{
		free(buffer);
		return (0);
	}

	read_result = read(file_descriptor, buffer, letters);
	if (read_result == -1)
	{
		free(buffer);
		close(file_descriptor);
		return (0);
	}

	write_result = write(STDOUT_FILENO, buffer, read_result);
	if (write_result == -1 || (size_t) write_result != (size_t) read_result)
	{
		free(buffer);
		close(file_descriptor);
		return (0);
	}

	free(buffer);
	close(file_descriptor);

	return (write_result);
}
