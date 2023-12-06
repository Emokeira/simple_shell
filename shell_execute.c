#include "main.h"

void executeCommand(char *args[])

{
	int status;
	pid_t pid, wpid;

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	else if ( pid == 0)
	{
		execvp(args[0], args);
		fprintf(stderr, "Error: No such file or directory\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		(void)wpid;
		do
		{
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}

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
