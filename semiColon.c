#include "main.h"

/**
 * handleSemiColon - Tokenize and handle commands separated by a semiColon
 * @segment: the command segments tobe processed
 **/

void handleSemiColon(char *segment)

{
	char *token, *trimmedSegment, *delimiter = ";";
	size_t len;

	token = strsep(&segment, delimiter);

	while (token != NULL)
	{
		trimmedSegment = token;
		while (*trimmedSegment == ' ' || *trimmedSegment == 't')
		{
			++trimmedSegment;
		}
		len = strlen(trimmedSegment);

		while (len > 0 && (trimmedSegment[len - 1] == ' ' ||
					trimmedSegment[len - 1] == 't'))
		{
			--len;
		}

		trimmedSegment[len] = '\0';

		if (strlen(trimmedSegment) > 0)
		{
			handleSegment(trimmedSegment);
		}

		token = strsep(&segment, delimiter);
	}
}
