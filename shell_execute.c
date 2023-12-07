#include "main.h"

/**
 * executeCommand - executes a command with it's arguments
 * in a new process
 * @args: Array of strings with the command and its arguments
 *
 */

void executeCommand(char *args[])

{
	int status;
	char *endptr;
	long exit_status;
	pid_t pid, wpid;

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execvp(args[0], args);
		fprintf(stderr, "Error: No such file or directory\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		(void)wpid;

		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		if (strcmp(args[0], "exit") == 0)
		{
			if (args[1] != NULL)
			{
				errno = 0;
				exit_status = strtol(args[1], &endptr, 10);

				if ((errno == ERANGE && (exit_status == LONG_MAX || exit_status == LONG_MIN
				)) || (errno != 0 && exit_status == 0) || *endptr != '\0')
				{
					perror("Error");
					_exit(EXIT_FAILURE);
				}

				_exit((int)exit_status);
			}
			else
			{
				_exit(EXIT_SUCCESS);
			}
		}
	}
}

/**
 * parseCommand - Parses a command into an array of arguments
 * and executes it
 * @command: The input to be parsed and executed
 */

void parseCommand(char *command)

{
	char *args[64], *token;
	int i = 0;
	char **env = environ;

	token = strtok(command, " ");

	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}

	args[i] = NULL;

	if (i > 0)
	{
		if (strcmp(args[0], "exit") == 0)
			exit(EXIT_SUCCESS);
		else if (strcmp(args[0], "env") == 0)
		{
			while (*env)
				printf("%s\n", *env++);
		}
		else
			executeCommand(args);
	}
}
