#include "shell.h"

/**
 * bfree - frees a pointer and sets the address to NULL
 * @ptr: the pointer to free
 *
 * Return: 1 if the pointer was successfully freed and NULLed, 0 otherwise.
 */
int bfree(void **ptr)
{
	if (ptr != NULL && *ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
