#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @str: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *str)
{
	int length = 0;

	if (!str)
	return (0);

	while (*str++)
	length++;

	return (length);
}

/**
 * string_compare - Compares two strings lexicographically.
 * @str1: the first strang
 * @str2: the second strang
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int string_compare(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
	if (*str1 != *str2)
	return (*str1 - *str2);
	str1++;
	str2++;
	}

	if (*str1 == *str2)
		return (0);
	else
		return (*str1 < *str2 ? -1 : 1);
}
