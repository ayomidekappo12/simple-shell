#include "shell.h"

/**
 * fill_memory - fills a memory area with a constant byte value
 * @memory_area: the pointer to the memory area
 * @byte_value: the byte value to fill *memory_area with
 * @num_bytes: the number of bytes to be filled
 *
 * Return: (memory_area) a pointer to the memory area
 */
char *fill_memory(char *memory_area, char byte_value, unsigned int num_bytes)
{
	for (unsigned int i = 0; i < num_bytes; i++)
		memory_area[i] = byte_value;

	return (memory_area);
}

/**
 * free_string_array - frees an array of strings
 * @string_array: the array of strings
 */
void free_string_array(char **string_array)
{
	char **temp = string_array;

	if (!string_array)
		return;

	while (*string_array)
		free(*string_array++);

	free(temp);
}
