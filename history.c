#include "shell.h"

/**
 * get_history_file - gets the path to the history file
 * @info: parameter struct
 *
 * Return: allocated string containing history file path
 */

char *get_history_file(info_t *info)
{
	char *buf, *home_dir;

	home_dir = _getenv(info, "HOME=");
	if (!home_dir)
		return (NULL);
	buf = malloc(sizeof(char) * (_strlen(home_dir) + _strlen(HIST_FILE) + 2));
	if (!buf)
		return (NULL);
	buf[0] = 0;
	_strcpy(buf, home_dir);
	_strcat(buf, "/");
	_strcat(buf, HIST_FILE);

	return (buf);
}

/**
 * write_history - writes the history to a file
 * @info: the parameter struct
 *
 * Return: 1 on success, else -1
 */
int write_history(info_t *info)
{
	ssize_t fd;
	char *filename = get_history_file(info);
	list_t *node = NULL;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);

	if (fd == -1)
		return (-1);

	for (node = info->history; node; node = node->next)
	{
		_putsfd(node->str, fd);
		_putfd('\n', fd);
	}
	_putfd(BUF_FLUSH, fd);
	close(fd);

	return (1);
}
