#include <stdio.h>

/**
 * customStrcmp - custom function that compares two strings
 * @str1: the first string
 * @str2: the second string
 *
 * Return: 0 if strings are equal
 *       : -1 if str1 is < str2
 *       : 1 is str1 is > str2
 */

int customStrcmp(const char *str1, const char *str2)
{
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (*str1 != *str2)
		{
			return (*str1 - *str2);
		}
	}
	str++;
	str2++;

	return (*str1 - *str2);
}

/**
 * main - entry point of the program
 * Return: 0 on success
 */

int main(void)
{
	char str1[] = "Hello";
	char str2[] = "Shell";

	int result = customStrcmp(str1, str2);

	printf("%d\n", result);

	return (0);
}

