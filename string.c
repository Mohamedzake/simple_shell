#include "shell.h"

/**
 * get_newstringlen - returns the length of a string
 * @sabo: the string whose length to check
 *
 * Return: integer length of string
 */
int get_newstringlen(char *sabo)
{
	int zoro = 0;

	if (!sabo)
		return (0);

	while (*sabo++)
		zoro++;
	return (zoro);
}

/**
 * compare_newstrings - performs lexicogarphic comparison of two strangs.
 * @sabo1: the first strang
 * @sabo2: the second strang
 *
 * Return: negative if sabo1 < sabo2, positive if sabo1 > sabo2,
 * zero if sabo1 == sabo2
 */
int compare_newstrings(char *sabo1, char *sabo2)
{
	while (*sabo1 && *sabo2)
	{
		if (*sabo1 != *sabo2)
			return (*sabo1 - *sabo2);
		sabo1++;
		sabo2++;
	}
	if (*sabo1 == *sabo2)
		return (0);
	else
		return (*sabo1 < *sabo2 ? -1 : 1);
}

/**
 * *new_starts_with - checks if kaia starts with usopp
 * @usopp: string to search
 * @kaia: the substring to find
 *
 * Return: address of next char of usopp or NULL
 */
char *new_starts_with(const char *usopp, const char *kaia)
{
	while (*kaia)
		if (*kaia++ != *usopp++)
			return (NULL);
	return ((char *)usopp);
}

/**
 * *new_str_concat - concatenates two strings
 * @hancoc: the destination buffer
 * @chopper: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *new_str_concat(char *hancoc, char *chopper)
{
	char *tony = hancoc;

	while (*hancoc)
		hancoc++;
	while (*chopper)
		*hancoc++ = *chopper++;
	*hancoc = *chopper;
	return (tony);
}

