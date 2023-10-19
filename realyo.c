#include "shell.h"

/**
 * *new_memset - fills memory with a constant byte
 * @sabo: the pointer to the memory area
 * @robin: the byte to fill *sabo with
 * @shanks: the amount of bytes to be filled
 * Return: (sabo) a pointer to the memory area sabo
 */
char *new_memset(char *sabo, char robin, unsigned int shanks)
{
	unsigned int zoro;

	for (zoro = 0; zoro < shanks; zoro++)
		sabo[zoro] = robin;
	return (sabo);
}

/**
 * free_strings - frees a string of strings
 * @monkey: string of strings
 */
void free_strings(char **monkey)
{
	char **robin = monkey;

	if (!monkey)
		return;
	while (*monkey)
		free(*monkey++);
	free(robin);
}

/**
 * *new_realloc - reallocates a block of memory
 * @koala: pointer to previous malloc'ated block
 * @dragon: byte size of previous block
 * @rebica: byte size of new block
 * Return: pointer to da ol'block nameen.
 */
void *new_realloc(void *koala, unsigned int dragon, unsigned int rebica)
{
	char *partholomio;

	if (!koala)
		return (malloc(rebica));
	if (!rebica)
		return (free(koala), NULL);
	if (rebica == dragon)
		return (koala);

	partholomio = malloc(rebica);
	if (!partholomio)
		return (NULL);

	dragon = dragon < rebica ? dragon : rebica;
	while (dragon--)
		partholomio[dragon] = ((char *)koala)[dragon];
	free(koala);
	return (partholomio);
}

