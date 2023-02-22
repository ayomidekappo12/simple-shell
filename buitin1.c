#include "shell.h"

/**
 * print_history - prints or displays the history lists,
 * one command per line, preceded by line numbers, starting at 0.
 *
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int print_history(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - unsets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
	char *equal_sign, temp_char;
	int ret;

	equal_sign = _strchr(str, '=');
	if (!equal_sign)
		return (1);
	 temp_char = *equal_sign;
	*equal_sign = '\0';
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*equal_sign = temp_char;
	return (ret);
}
