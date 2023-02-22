#include "shell.h"

/**
 * _myenv - prints the current environment
 * @info: Structure containing potential arguments. Used to maintain
 *  constant function prototype.
 * Return: Always 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - gets the value of an environ variable
 * @info: Structure containing potential arguments. Used to maintain
 * @name: Name of the environment variable to get the value for .
 *
 * Return: the value of the environment variable, or NULL if not found
 */
char *_getenv(info_t *info, const char *name)
{
	/* set the initial node to the beginning of the linked list. */
	list_t *env_list = info->env;
	/* pointer to the value of the environment variable */
	char *env_var_value;

	/* iterate over the linked list to find the environment variable */
	while (env_list)
	{
		/* check if the current node starts with the environment variable name. */
		env_var_value = starts_with(env_list->str, name);
		if (env_var_value && *env_var_value)
			return (env_var_value);
		env_list = env_list->next;
	}
	return (NULL);
}

