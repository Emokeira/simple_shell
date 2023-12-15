#include "main.h"

#define MAX_ARGS 10


/**
 * tokenizeAndHandle - tokenizes a command and handles the arguments
 * @segment: the command segment to be tokenized
 *
 * Return: 1 if the command is not a built-in command, 0 if otherwise
 */

int tokenizeAndHandle(char *segment)
{
	char *token = custom_strtok(segment, " ");
	char *args[MAX_ARGS] = {NULL};
	int i = 0, count = 0;

	while (token != NULL && i < MAX_ARGS - 1)
	{
		args[i++] = token;
		count++;
		token = custom_strtok(NULL, " ");
	}

	args[i] = NULL;
	printf("%d\n", count);

	if (!handleBuiltInCommands(args))
	{
		return (1);
	}

	return (0);
}

/**
 * handleAndOperator - handles command segments with the '&&' operator
 * @segment: the command to be processed
 */

void handleAndOperator(char *segment)
{
	char *args[] = {NULL, NULL};
	char *andOperator = "&&", *operator;
	int status;

	operator = strstr(segment, andOperator);

	if (operator != NULL)
	{
		*operator = '\0';
		args[0] = segment;

		status = tokenizeAndHandle(args[0]);

		if (status == 0)
		{
			processCommandSegments(operator + strlen(andOperator));
		}
	}
}

/**
 * handleOrOperator - handles command segmemts with the '||' operator
 * @segment: the command segement to be processed
 */

void handleOrOperator(char *segment)
{
	char *args[] = {NULL, NULL};
	char *orOperator = "||", *operator;
	int status;

	operator = strstr(segment, orOperator);

	if (operator != NULL)
	{
		*operator = '\0';
		args[0] = segment;

		status = tokenizeAndHandle(args[0]);

		if (status != 0)
		{
			processCommandSegments(operator + strlen(orOperator));
		}
	}
}
