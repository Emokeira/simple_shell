#include "main.h"

#define MAX_BUFFER_SIZE_1024

/**
 * main - the entry point of the program
 * @argc: the number of command-line arguments
 * @argv: array of strings with the command-line arguments
 * Return: 0 on success.
 */

int main(int argc, char *argv[])
{
	if (isatty(STDIN_FILENO))
	{
		char *buffer = NULL;

		while (write(STDOUT_FILENO, "$ ", 2) && fflush(stdout) == 0)
		{
			buffer = _getLine();

			if (buffer[0] == '\0' || buffer[0] == '\n')
			{
				break;
			}

			buffer[strlen(buffer) - 1] = '\0';

			if (buffer[0] != '\0')
			{
				processCommandSegments(buffer);
			}

			free(buffer);
			buffer = NULL;
		}
	} else
	{
		handleNonInteractiveMode(argc, argv);
	}

	fflush(stdout);
	return (0);
}

/**
 * executeCommandsFromFile - reads and commands file from a file descriptor
 * @file_descriptor: the file descriptor from which commands are read
 */

void executeCommandsFromFile(int file_descriptor)
{
	char *buffer = NULL;
	size_t bufsize = MAX_BUFFER_SIZE;
	ssize_t bytesRead;

	buffer = (char *)malloc(MAX_BUFFER_SIZE);

	if (buffer == NULL)
	{
		write(STDERR_FILENO, "malloc", 6);
		exit(EXIT_FAILURE);
	}

	while ((bytesRead = read(file_descriptor, buffer, bufsize)) != -1)
	{
		if (bytesRead > 0)
		{
			buffer[bytesRead - 1] = '\0';
			processCommandsegments(buffer);
		}
	}
	free(buffer);
	close(file_descriptor);
}
/**
 * handleNonInteractiveMode - handles the program in non-interactive mode
 * @argc: the number of command-line arguments
 * @argv: array of strings representing the command line arguments
 */

void handleNonInteractiveMode(int argc, char *argv[])
{
	if (argc > 1)
	{
		int file_descriptor = open(argv[1], O_RDONLY);

		if (file_descriptor == -1)
		{
			write(STDERR_FILENO, "Error opening file\n", 19);
			perror("open");
			_exit(EXIT_FAILURE);
		}

		executeCommandsFromFile(file_descriptor);
	}
	else
	{
		if (write(STDERR_FILENO, "Usage: ", 7) == -1 ||
			write(STDERR_FILENO, argv[0], strlen(argv[0])) == -1 ||
			write(STDERR_FILENO, " <filename>\n", 12) == -1)
		{
			perror("write");
			_exit(EXIT_FAILURE);
		}

		_exit(EXIT_FAILURE);
	}

	_exit(EXIT_FAILURE);
}
