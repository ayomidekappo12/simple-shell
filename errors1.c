#include "shell.h"

/**
 * string_to_int - converts a string to an integer
 *
 * @string: the string to be converted
 *
 * Return: 0 if no numbers in string, converted number otherwise
 *       -1 on error
 */
int string_to_int(char *string)
{
	int index = 0;
	unsigned long int result = 0;

	if (*string == '+')
		string++;
	for (index = 0;  string[index] != '\0'; index++)
	{
		if (string[index] >= '0' && string[index] <= '9')
		{
			result *= 10;
			result += (string[index] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - prints an error message in the format
 *	 "filename: line number: command: error message" to standard error.
 *
 * @info: the parameter & return info struct
 * @estr: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *	-1 on error
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_decimal(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}
