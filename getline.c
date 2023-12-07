#include "main.h"

#define GET_SIZE 1024

/**
 * buffer_allocation - Allocates memory for a buffer
 * @getPtr: Pointer to the buffer pointer
 * @a: pointer to the size variable
 *
 */


void buffer_allocation(char **getPtr, size_t *a)

{
	*a = GET_SIZE;
	*getPtr = (char *)malloc(*a);
	if (!*getPtr)
	{
		perror("custom getline malloc");
		exit(EXIT_FAILURE);
	}
}

/**
 * _getline - reads a line from a stream and stores it in a buffer
 * @getPtr: pointer to the buffer pointer
 * @a: pointer to the size variable
 * @stream: the input stream
 * Return: Number of characters read, or -1 on failure
 */

ssize_t _getline(char **getPtr, size_t *a, FILE *stream)

{
	char currentChar;
	size_t i = 0, buffer_index = 0;
	static char buffer[GET_SIZE];

	if (*getPtr == NULL || *a == 0)
		buffer_allocation(getPtr, a);

	printf("$ ");

	while (1)
	{
		if (buffer_index == 0 && read(fileno(stream), buffer, GET_SIZE) == 0)
		{
			if (i == 0)
			{
				return (-1);
			}
		}
		if (i >= *a - 1)
		{
			*a += GET_SIZE;
			free(*getPtr);
			buffer_allocation(getPtr, a);
		}

		currentChar = buffer[buffer_index++];
		(*getPtr)[i++] = currentChar;

		if (currentChar == '\n')
			break;
		if (buffer_index == GET_SIZE)
			buffer_index = 0;
	}
	(*getPtr)[i] = '\0';

	return (i);
}
