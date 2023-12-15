#include "main.h"

char *searchCommandInPath(char *args[])
{
	char *path = getenv("PATH"), *token, *command_path;
	char *path_copy = strdup(path);

	if (path_copy == NULL)
	{
		perror("Error duplicating PATH");
		return NULL;
	}

	if (access(args[0], X_OK) == 0)
		return (path_copy);

	token = strtok(path_copy, ":");
	command_path = NULL;

	while (token != NULL)
	{
		size_t path_length = strlen(token);
		size_t command_length = strlen(args[0]);
		size_t total_length = path_length + command_length + 2;
		command_path = (char *)malloc(total_length);

		if (command_path == NULL)
		{
			perror("Error allocating memory for command_path");
			free(path_copy);
			return NULL;
		}

		snprintf(command_path, total_length, "%s/%s", token, args[0]);
		printf("%s\n", command_path);

		if (access(command_path, X_OK) == 0)
		{
			free(path_copy);
			return command_path;
		}

		free(command_path);
		token = strtok(NULL, ":");
	}

	free(path_copy);
	return NULL;
}
