#include "main.h"

/**
 * handleBuiltInCommands - handles built-in shell commands
 * @args: array of string containing command arguments
 * Return: 0 on success
 */

int handleBuiltInCommands(char *args[])
{
	if (strcmp(args[0], "exit") == 0)
	{
		exitShell();
	}
	else if (strcmp(args[0], "env") == 0)
	{
		printEnvironment();
	}
	else if (strcmp(args[0], "setenv") == 0)
	{
		setEnvironmentVariable(args);
	}
	else if (strcmp(args[0], "unsetenv") == 0)
	{
		unsetEnvironmentVariable(args);
	}
	else if (strcmp(args[0], "cd") == 0)
	{
		changeDirectory(args);
	}
	else
	{
		executeCommand(args);
	}
	return (0);
}
