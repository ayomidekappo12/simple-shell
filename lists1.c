#include "shell.h"

/**
 * list_len - determines the length of a linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t list_len(const list_t *h)
{
	size_t count = 0;

	while (h)
	{
		h = h->next;
		count++;
	}
	return (count);
}
