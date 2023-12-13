#include "main.h"

extern char **environ;

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
/**
 * exitShell- exits shell with a success status
 */

void exitShell(void)
{
	fflush(stdout);
	exit(EXIT_SUCCESS);
}
/**
 * printEnvironment - prints environment variables
 * to standard output
 */
void printEnvironment(void)
{
	char *env_var;
	int i = 0;

	while ((env_var = environ[i]) != NULL)
	{
		write(STDOUT_FILENO, env_var, strlen(env_var));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

/**
 * setEnvironmentVariable - sts environment variable based on arguments
 * @args: array of string containing command arguments
 */

void setEnvironmentVariable(char *args[])
{
	if (args[1] != NULL && args[2] != NULL)
	{
		if (setenv(args[1], args[2], 1) != 0)
		{
			write(STDERR_FILENO, "Error: Unable to set environment variable\n",
					strlen("Error: Unable to set environment variable\n"));
		}
	}
	else
	{
		write(STDERR_FILENO, "Error: Incorrect number of arguments for setenv\n",
				strlen("Error: Incorrect number of arguments for setenv\n"));
	}
}

/**
 * unsetEnvironmentVariable - unsets environment variable
 * based on command arguments
 * @args: array of string containing arguments
 */

void unsetEnvironmentVariable(char *args[])
{
	if (args[1] != NULL)
	{
		if (unsetenv(args[1]) != 0)
		{
			write(STDERR_FILENO, "Error: Unable to unset environment variable\n",
					strlen("Error: Unable to unset environment variable\n"));
		}
		else
		{
			write(STDERR_FILENO, "Error: Incorrect number of arguments for unsetenv\n",
					strlen("Error: Incorrect number of arguments for unsetenv\n"));
		}
	}
}

/**
 * changeDirectory - changes the current working directory
 * based on command arguments
 * @args: array of strings containing arguments
 */

void changeDirectory(char *args[])
{
	char *dir = args[1];
	char *oldpwd = getenv("PWD");

	if (dir == NULL)
	{
		dir = getenv("HOME");
	}
	else if (strcmp(dir, "-") == 0)
	{
		dir = getenv("OLDPWD");
	}

	if (chdir(dir) != 0)
	{
		perror("Error: Unable to change directory");
	}
	else
	{
		setenv("OLDPWD", oldpwd, 1);
		updatePWD();
	}
}
