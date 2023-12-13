#include "shell.h"

/**
 **_memset - fills memory with a constant byte
 *@s: the pointer to the memory area
 *@b: the byte to fill *s with
 *@n: the amount of bytes to be filled
 *Return: (s) a pointer to the memory area s
 */
char *_memset(char *l, char p, unsigned int g)
{
	unsigned int i;

	for (i = 0; i < g; i++)
		l[i] = p;
	return (l);
}

/**
 * ffree - frees a string of strings
 * @pp: string of strings
 */
void ffree(char **bb)
{
	char **j = bb;

	if (!bb)
		return;
	while (*bb)
		free(*bb++);
	free(j);
}

/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer to previous malloc'ated block
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 *
 * Return: pointer to da ol'block nameen.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *b;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	b = malloc(new_size);
	if (!b)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		b[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (b);
}
