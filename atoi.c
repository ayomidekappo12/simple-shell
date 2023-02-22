#include "shell.h"

/**
 * interactive_program - returns true if the shell is in interactive mode
 * @info: structure address
 *
 * Return: 1 or true if interactive mode, 0 or false otherwise
 */

int interactive_program(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if character is  delimeter
 * @c: the char to check
 * @delim: the delimeted strings
 * Return: 1 if true, 0 if false
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

