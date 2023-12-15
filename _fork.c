#include "main.h"

/**
 * executeCommand - execute the fork process
 * @args: array of characters to be passed as arguments
 **/
void executeCommand(char *args[])
{
	int status = 0;
	char *command_path;
	pid_t pid = -1;

	command_path = searchCommandInPath(args);

	if (command_path != NULL)
	{
		pid = fork();
		if (pid == -1)
		{
			write(STDERR_FILENO, "Error\n", strlen("Error\n"));
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
			executeChild(args);
		else
		{
			int wstatus;

			waitpid(pid, &wstatus, 0);
			status = wstatus;

			if (strcmp(args[0], "exit") == 0)
				handleExit(args);

			if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
			{
			}

			free(command_path);
		}
	}
	else
		write(STDERR_FILENO, "Error: Command not found in PATH\n",
				strlen("Error: Command not found in PATH\n"));
}
/**
 * searchCommandInPath - searches for the command in
 *			the PATH directory and return the path
 * @args: array of characters to be passed as argument
 * Return: Returns NULL if the command is not found
 **/
/**
char *searchCommandInPath(char *args[])
{
	char *path = getenv("PATH"), *command_path = NULL;
	char *path_copy = strdup(path);
	char *token = custom_strtok(path_copy, ":");

	while (token != NULL)
	{
		command_path = (char *)malloc(strlen(token) + strlen(args[0]) + 2);
		sprintf(command_path, "%s/%s", token, args[0]);

		if (access(command_path, X_OK) == 0)
		{
			free(path_copy);
			return (command_path);
		}

		free(command_path);
		token = custom_strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
**/
