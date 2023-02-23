#include "shell.h"

/**
 * bfree - frees a pointer and sets the address to NULL
 * @pointer_to_free: the pointer to free
 *
 * Returns: 1 if the pointer was freed, otherwise 0
 */
int bfree(void **pointer_to_free)
{
	if (pointer_to_free != NULL && *pointer_to_free != NULL)
	{
		free(*pointer_to_free);
		*pointer_to_free = NULL;
		return (1);
	}
	return (0);
}
