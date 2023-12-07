#include "main.h"

/**
 * main - The entry point of the shell program
 *
 * Return: Always 0 (success)
 */

int main(void)

{
	char *buffer = NULL;

	while (1)
	{
		printf("$ ");
		fflush(stdout);

		buffer = readLine();

		if (buffer[0] == '\0')
		{
			break;
		}
		buffer[strlen(buffer) - 1] = '\0';

		if (buffer[0] != '\0')
		{
/**			printf("%s\n", buffer); **/
			parseCommand(buffer);
		}

		free(buffer);
	}

	fflush(stdout);

	return (0);
}
