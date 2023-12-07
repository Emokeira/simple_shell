
/*
 * custom_strtok - custom implementation of the strtok function
 * which tokenizes a string based on the specified delimiter
 * Maintains state accross calls using a static pointer
 * @str: a pointer to the string to be tokenized
 * @delim: a pointer to the string with the delimiter characters
 *
 * Return: a pointer to the next token in the string
 * or NULL if no more tokens
 */

char *custom_strtok(char *str, const char *delim)
{
	static char *current;
	char *start, *end;

	if (str != NULL)
	{
		current = str;
	}

	if (current == NULL || *current == '\0')
	{
		return (NULL);
	}

	while (*current != '\0' && strchr(delim, *current) != NULL)
	{
		++current;
	}
	if (*current == '\0')
	{
		return (NULL);
	}
	start = current;
	end = strpbrk(start, delim);

	if (end == NULL)
	{
		current += strlen(start);
	}
	else
	{
		*end = '\0';
		current = end + 1;
	}

	return (start);
}
