#include "main.h"

extern char **environ;

void _builtFunctions(char *args[])

{
	if (strcmp(args[0], "exit") == 0)
	{
		fflush(stdout);
		exit(EXIT_SUCCESS);
	}
	else if (strcmp(args[0], "env") == 0)
	{
		char *env_var;
		int i = 0;
		while ((env_var = environ[i]) != NULL)
		{
			printf("%s\n", env_var);
			i++;
		}
	}
	else if (strcmp(args[0], "setenv") == 0)
	{
		if (args[1] != NULL && args[2] != NULL)
		{
			if (setenv(args[1], args[2], 1) != 0)
			{
				fprintf(stderr, "Error: Unable to set environment variable\n");
			}
		}
		else
		{
			fprintf(stderr, "Error: Incorrect number of arguments for setenv\n");
		}
	}
	else if (strcmp(args[0], "unsetenv") == 0)
	{
		if (args[1] != NULL)
		{
			if (unsetenv(args[1]) != 0)
			{
				fprintf(stderr, "Error: Unable to unset environment variable\n");
			}
		}
		else
		{
			fprintf(stderr, "Error: Incorrect number of arguments for unsetenv\n");
		}
	}
	else
	{
		executeCommand(args);
	}
}

void parseCommand(char *command)

{
	char *args[64], *token;
	int i = 0;

	token = custom_strtok(command, " ");

	while (token != NULL)
	{
		args[i++] = token;
		token = custom_strtok(NULL, " ");
	}

	args[i] = NULL;

	if (i > 0)
	{
		_builtFunctions(args);
	}
}
