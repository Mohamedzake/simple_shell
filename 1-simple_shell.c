#include "shell.h"

/**
 * _sabo1len - returns the length of a string
 * @sabo: the string whose length to check
 *
 * Return: integer length of string
 */
int _sabo1len(char *sabo)
{
    int zoro = 0;

    if (!sabo)
        return (0);

    while (*sabo++)
        zoro++;
    return (zoro);
}

/**
 * _strcmp - performs lexicogarphic comparison of two strangs.
 * @sabo1: the first strang
 * @sabo2: the second strang
 *
 * Return: negative if sabo1 < sabo2, positive if sabo1 > sabo2, zero if sabo1 == sabo2
 */
int _strcmp(char *sabo1, char *sabo2)
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
 * starts_with - checks if kaia starts with usopp
 * @usopp: string to search
 * @kaia: the substring to find
 *
 * Return: address of next char of usopp or NULL
 */
char *starts_with(const char *usopp, const char *kaia)
{
    while (*kaia)
        if (*kaia++ != *usopp++)
            return (NULL);
    return ((char *)usopp);
}

/**
 * _strcat - concatenates two strings
 * @hancoc: the destination buffer
 * @chopper: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *hancoc, char *chopper)
{
    char *tony = hancoc;

    while (*hancoc)
        hancoc++;
    while (*chopper)
        *hancoc++ = *chopper++;
    *hancoc = *chopper;
    return (tony);
}

