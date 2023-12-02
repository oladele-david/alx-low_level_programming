#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define BUFF_SIZE 1024

/**
 *create_buffer - Allocates 1024 bytes for a buffer.
 *@file: The name of the file buffer is storing chars for.
 *
 *Return: A pointer to the newly-allocated buffer.
 */
char *create_buffer(char *file)
{
	char *buffer = malloc(sizeof(char) *BUFF_SIZE);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 *close_file - Closes file descriptor.
 *@fd: The file descriptor to be closed.
 *@filename: The name of the file associated with the file descriptor.
 */
void close_file(int fd, char *filename)
{
	int c = close(fd);
	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		dprintf(STDERR_FILENO, "Error: Can't close file %s\n", filename);
		exit(100);
	}
}

/**
 *main - Copies the contents of a file to another file.
 *@argc: The number of arguments supplied to the program.
 *@argv: An array of pointers to the arguments.
 *
 *Return: 0 on success.
 */
int main(int argc, char *argv[])
{
	int from, to, r, w;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);

	from = open(argv[1], O_RDONLY);
	if (from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		free(buffer);
		exit(98);
	}

	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close_file(from, argv[1]);
		free(buffer);
		exit(99);
	}

	do {
		r = read(from, buffer, BUFF_SIZE);
		if (r == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			close_file(from, argv[1]);
			close_file(to, argv[2]);
			free(buffer);
			exit(98);
		}

		w = write(to, buffer, r);
		if (w == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			close_file(from, argv[1]);
			close_file(to, argv[2]);
			free(buffer);
			exit(99);
		}
	} while (r > 0);

	free(buffer);
	close_file(from, argv[1]);
	close_file(to, argv[2]);

	return (0);
}
