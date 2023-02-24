#include "shell.h"

/**
 * bfree - frees a pointer and NULLs the address
 * @ptr: the pointer to free
 *
 * Return: 1 if the pointer was freed, otherwise 0
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
