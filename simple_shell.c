#include "main.h"

#define MAX_BUFFER_SIZE 1024

/**
 * main - Entry point of the program
 * @argc: Number of arguments passed to the program
 * @argv: Array of strings containing the command-line arguments
 *
 * Return: EXIT_SUCCESS upon successful completion
 **/

int main(int argc, char *argv[])
{
	char *buffer = NULL;

	if (argc > 1)
		return (1);

	(void)argv;
	while (1)
	{
		if (isatty(STDIN_FILENO) && argc == 1)
			write(STDOUT_FILENO, "$ ", 2);

		buffer = _getline();

		if (buffer[0] == '\0' || buffer[0] == '\n')
		{
			break;
		}
		buffer[strlen(buffer) - 1] = '\0';

		if (buffer[0] != '\0')
		{
			processCommandSegments(buffer);
		}
		buffer = NULL;
	}
	fflush(stdout);
	_exit(EXIT_SUCCESS);
}
/**
 * executeCommandsFromFile - Execute commands read from a file descriptor
 * @file_descriptor: file descriptor for the input source
 *
 * This function reads commands from the specified file descriptor
 * processes each command, and execute them accordingly.
 **/

void executeCommandsFromFile(int file_descriptor)
{
	char *buffer = NULL;
	size_t bufSize = MAX_BUFFER_SIZE;
	ssize_t bytesRead;

	buffer = (char *)malloc(MAX_BUFFER_SIZE);
	if (buffer == NULL)
	{
		write(STDERR_FILENO, "malloc", 6);
		exit(EXIT_FAILURE);
	}

	while ((bytesRead = read(file_descriptor, buffer, bufSize)) != -1)
	{
		if (bytesRead > 0)
		{
			buffer[bytesRead - 1] = '\0';
			processCommandSegments(buffer);
		}
	}
	free(buffer);
	close(file_descriptor);
}

/**
 * handleNonInteractiveMode - handle non-interactive mode
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 *
 * This function handles non-interactive mode by either opening and
 * executing commands from file or displaying a usage message.
 **/

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
	}
	_exit(EXIT_FAILURE);
}
