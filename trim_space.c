#include "main.h"
#include <ctype.h>

/**
 * trimSpaces - function that trims leading and trailing spaces from a string
 * @str: the input string to be trimmed
 *
 * Return: a pointer to the trimmed string
 */

char *trimSpaces(char *str)
{
	char *end;

	while (isspace((unsigned char)*str))
	{
		str++;
	}

	if (*str == '\0')
	{
		return (str);
	}

	end = str + strlen(str) - 1;
	while (end > str && isspace((unsigned char)*end))
	{
		end--;
	}

	*(end + 1) = '\0';

	return (str);
}

/**
 * updatePWD - updates the PWD environment variable
 * with the current working directory
 */

void updatePWD(void)
{
	char cwd[1024];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		setenv("PWD", cwd, 1);
	}
}
