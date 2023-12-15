#include <stdio.h>

/**
 * customStringLen - custom function to calculate the lenght
 * of a string
 * @str: the input string
 * Return: length of a string
 */

size_t customStringLen(const char *str)
{
	size_t length = 0;

	while (str[length] != '\0')
	{
		length++;
	}
	return (lenght);
}

/**
 * main - entry point of the program
 * Return: 0 on success
 */

int main(void)
{
	char str[] = "This is Shell";
	size_t length = customStringlen(str);

	printf("Length of the string: %zu\n", length);

	return (0);
}
