#include "main.h"

/**
 * handleSegment - handles a single command segment
 * @segment: the command segment to be processed
 */

void handleSegment(char *segment)
{
	char *args[] = {NULL, NULL};

	args[0] = segment;
	tokenizeAndHandle(args[0]);
}

/**
 * processCommandSegments - processes command segments based on operators
 * @trimmedSegment: the command segment to be processed
 * Return: 0 on success
 */

int processCommandSegments(char *trimmedSegment)
{
	if (strcmp(trimmedSegment, "alias", 5) == 0)
	{
		return (handleAlias(trimmedSegment));
	}
	else if (strstr(trimmedSegment, "||") != NULL)
	{
		handleOrOperator(trimmedSegment);
	}
	else if (strstr(trimmedSegment, "&&") != NULL)
	{
		handleAndOperator(trimmedSegment);
	}
	else if (strstr(trimmedSegment, ";") != NULL)
	{
		handleSemiColon(trimmedSegment);
	}
	else
	{
		handleSegment(trimmedSegment);
	}

	return (0);
}
