#include "main.h"

/**
 * executeChild - Execute the child command in the child process
 * @args: array of strings containing the command and it's arguments
 **/

void executeChild(char *args[])
{

		if (strchr(args[0], '/') == NULL)
		{
			char *path = getenv("PATH");
			char *pathCopy = strdup(path);
			char *dir = custom_strtok(pathCopy, ":");

			while (dir != NULL)
			{
				char fullPath[1024];

				snprintf(fullPath, sizeof(fullPath), "%s/%s", dir, args[0]);
				execve(fullPath, args, environ);
				dir = custom_strtok(NULL, ":");
			}
			write(STDERR_FILENO, "Error: Command not found in PATH\n",
					strlen("Error: Command not found in PATH\n"));
			free(pathCopy);
			exit(EXIT_FAILURE);
		}
		else
		{
			execve(args[0], args, environ);
			write(STDERR_FILENO, "Error: No such file or directory\n",
					strlen("Error: No such file or  directory\n"));
			exit(EXIT_FAILURE);
		}
}

/**
 * handleExit - handles the 'exit' built-in-command
 * @args: array of strings with command arguments
 */

void handleExit(char *args[])
{
	int status;
	char *endptr;
	long exit_status;
	pid_t wpid;

	do {
		wpid = waitpid(-1, &status, WUNTRACED);
	} while (wpid > 0 && !WIFEXITED(status) && !WIFSIGNALED(status));

	if (args[1] != NULL)
	{
		errno = 0;
		exit_status = strtol(args[1], &endptr, 10);

		if ((errno == ERANGE && (exit_status == LONG_MAX ||
						exit_status == LONG_MIN)) ||
			(errno != 0 && exit_status == 0) || *endptr != '\0')
		{
			perror("Error\n");
			_exit(EXIT_FAILURE);
		}

		_exit((int)exit_status);
	}
	else
	{
		_exit(EXIT_SUCCESS);
	}
}
