#include "main.h"

#define BUFFER_SIZE 256

static char buffer[BUFFER_SIZE];
static size_t currentPosition;

/**
 * _getline - custom function to read a line from std input
 *
 * Return: a pointer to the string containing the line
 **/

char *_getline()
{
	if (currentPosition == 0)
	{
		ssize_t bytesRead = read(STDIN_FILENO, buffer, BUFFER_SIZE - 1);

		if (bytesRead <= 0)
		{
			buffer[currentPosition] = '\0';
			return (buffer);
		}
		currentPosition += bytesRead;
	}
	return (_getlineHelper());
}

/**
 * _getlineHelper - helper function for processing the buffer
 * and extracting a line
 *
 * Return: a pointer to the string containing the line
 **/

char *_getlineHelper()
{
	size_t i;

	for (i = 0; i < currentPosition; i++)
	{
		if (buffer[i] == '\n')
		{
			if (i < BUFFER_SIZE - 1)
			{
				buffer[i + 1] = '\0';
			}
			else
			{
				buffer[i] = '\0';
			}
			memmove(buffer, buffer + i + 1, currentPosition - i - 1);
			currentPosition -= i + 1;
			return (buffer);
		}
	}
	currentPosition = 0;
	return (_getline());
}
