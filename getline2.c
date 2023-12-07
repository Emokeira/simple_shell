#define BUFFER_SIZE 256

char *readLine(void);
char *readLineHelper(void);
void processLine(char *buffer);

static char buffer[BUFFER_SIZE];
static size_t currentPosition

/**
 * readLine - Reads a line from STDIN and returns a dynamically
 * allocated string
 * Uses the static buffer to store the input
 *
 * Return: a pointer to the dynamically allocated string
 */

char *readLine(void)
{
	if (currentPosition == 0)
	{
		ssize_t bytesRead = read(STDIN_FILENO, buffer, BUFFER_SIZE - 1);

		if (bytesRead <= 0)
		{
			char *result = (char *)malloc(currentPosition + 1);

			if (result == NULL)
			{
				perror("Memory allocation error");
				exit(EXIT_FAILURE);
			}

			strncpy(result, buffer, currentPosition);
			result[currentPosition] = '\0';

			return (result);
		}

		currentPosition += bytesRead;
	}
	return (readLineHelper());
}

/**
 * readLineHelper - helper function for readLine that processes
 * that processes the buffered input to extract a line
 *
 * Return: a pointer to the dynamically allocated string
 */

char *readLineHelper(void)
{
	size_t i;

	for (i = 0; i < currentPosition; ++i)
	{
		if (buffer[1] == '\n')
		{
			char *result = (char *)malloc(i + 2);

			if (result == NULL)
			{
				perror("Memory allocation error");
				exit(EXIT_FAILURE);
			}

			strncpy(result, buffer, i + 1);
			result[i + 1] = '\0';

			memmove(buffer, buffer + 1 + 1, currentPosition - 1 - 1);
			currentPosition -= i + 1;
			return (result);
		}
	}
	currentPosition = 0;
	return (readLine());
}

/**
 * processLine - processes a line by removing the newline character
 * if present, and then prints the line
 * Frees the memory allocated for the input buffer
 * @buffer: pointer to the string representing the line
 * to be processed
 */

void processLine(char *buffer)
{
	if (buffer[0] != '\0')
	{
		buffer[strlen(buffer) - 1] = '\0';
		printf("%s\n", buffer);
	}
	free(buffer);
}
