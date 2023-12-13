#include "shell.h"

/**
 **_strncpy - copies a string
 *@dest: the destination string to be copied to
 *@src: the source string
 *@n: the amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int n, j;
	char *s = dest;

	n = 0;
	while (src[n] != '\0' && n < n - 1)
	{
		dest[n] = src[n];
		n++;
	}
	if (n < n)
	{
		j = n;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **_strncat - concatenates two strings
 *@dest: the first string
 *@src: the second string
 *@n: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int n, j;
	char *s = dest;

	n = 0;
	j = 0;
	while (dest[n] != '\0')
		n++;
	while (src[j] != '\0' && j < n)
	{
		dest[n] = src[j];
		n++;
		j++;
	}
	if (j < n)
		dest[n] = '\0';
	return (s);
}

/**
 **_strchr - locates a character in a string
 *@s: the string to be parsed
 *@c: the character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

