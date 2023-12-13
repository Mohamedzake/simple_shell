#include "shell.h"

/**
 * **strtow - splits a string into words. Repeat delimiters are ignored
 * @str: the input string
 * @d: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strtow(char *str, char *d)
{
	int g, j, k, w, numwords = 0;
	char **c;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (g = 0; str[g] != '\0'; g++)
		if (!is_delim(str[g], d) && (is_delim(str[g + 1], d) || !str[g + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	c = malloc((1 + numwords) * sizeof(char *));
	if (!c)
		return (NULL);
	for (g = 0, j = 0; j < numwords; j++)
	{
		while (is_delim(str[g], d))
			g++;
		k = 0;
		while (!is_delim(str[g + k], d) && str[g + k])
			k++;
		c[j] = malloc((k + 1) * sizeof(char));
		if (!c[j])
		{
			for (k = 0; k < j; k++)
				free(c[k]);
			free(c);
			return (NULL);
		}
		for (w = 0; w < k; w++)
			c[j][w] = str[g++];
		c[j][w] = 0;
	}
	c[j] = NULL;
	return (c);
}

/**
 * **strtow2 - splits a string into words
 * @str: the input string
 * @d: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char d)
{
	int f, j, k, w, numwords = 0;
	char **c;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (f = 0; str[f] != '\0'; f++)
		if ((str[f] != d && str[f + 1] == d) ||
		    (str[f] != d && !str[f + 1]) || str[f + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	c = malloc((1 + numwords) * sizeof(char *));
	if (!c)
		return (NULL);
	for (f = 0, j = 0; j < numwords; j++)
	{
		while (str[f] == d && str[f] != d)
			f++;
		k = 0;
		while (str[f + k] != d && str[f + k] && str[f + k] != d)
			k++;
		c[j] = malloc((k + 1) * sizeof(char));
		if (!c[j])
		{
			for (k = 0; k < j; k++)
				free(c[k]);
			free(c);
			return (NULL);
		}
		for (w = 0; w < k; w++)
			c[j][w] = str[f++];
		c[j][w] = 0;
	}
	c[j] = NULL;
	return (c);
}

