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

/**
 * _mysetenv - Initialize a new environment variable
 * or modifies an existing one.
 * @info: Structure containing potential arguments. Used to maintain
 *  constant function prototype.
 *  Return: Always 0
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Usage: setenv VARIABLE VALUE\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
	{
		return (0);
	}
	else
	{
		return (1);
	}
}

/**
 * _myunsetenv - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Always 0
 */
int _myunsetenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Usage: unsetenv VARIABLE VALUE\n");
		return (1);
	}
	/* remove each argument as an environment variable */
	for (i = 1; i <= info->argc; i++)
	{
		_unsetenv(info, info->argv[i]);
	}

	return (0);
}

/**
 * populate_env_list - populates the environment
 * linked list with environment variable
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
