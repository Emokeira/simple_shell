#include "main.h"

/**
 * main - Entry point for the program
 *
 * Return: Always returns o
 */

int main(void)

{
	char *buffer = NULL;

	while (1)
	{
		printf("$ ");
		fflush(stdout);

		buffer = _getline();
		if (buffer[0] == '\0')
		{
			break;
		}

		buffer[strlen(buffer) - 1] = '\0';

		if (buffer[0] != '\0')
		{
			parseCommand(buffer);
		}
		free(buffer);
	}

	fflush(stdout);

	return (0);
}
