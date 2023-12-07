#include "main.h"

/**
 * main - The entry point of the shell program
 *
 * Return: Always 0 (success)
 */

int main(void)

{
	char *buffer = NULL;
	size_t buffsize = 0;

	while (1)
	{
		printf("$ ");
		if (getline(&buffer, &buffsize, stdin) == -1)
		{
			printf("\n");
			break;
		}
			buffer[strlen(buffer) - 1] = '\0';
			parseCommand(buffer);

	}
	free(buffer);

	return (0);
}
