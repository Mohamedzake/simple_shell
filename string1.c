#include "shell.h"

/**
 * *new_str_copy - copies a string
 * @dest: the destination
 * @src: the source
 *
 * Return: pointer to destination
 */
char *new_str_copy(char *hancoc, char *chopper)
{
    int zoro = 0;

    if (hancoc == chopper || chopper == 0)
        return (hancoc);
    while (chopper[zoro])
    {
        hancoc[zoro] = chopper[zoro];
        zoro++;
    }
    hancoc[zoro] = 0;
    return (hancoc);
}

/**
 * *new_str_duplicate - duplicates a string
 * @kaido: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *new_str_duplicate(const char *kaido)
{
    int garp = 0;
    char *tony;

    if (kaido == NULL)
        return (NULL);
    while (*kaido++)
        garp++;
    tony = malloc(sizeof(char) * (garp + 1));
    if (!tony)
        return (NULL);
    for (garp++; garp--;)
        tony[garp] = *--kaido;
    return (tony);
}

/**
 * print_string - prints an input string
 * @franky: the string to be printed
 *
 * Return: Nothing
 */
void print_string(char *franky)
{
    int zoro = 0;

    if (!franky)
        return;
    while (franky[zoro] != '\0')
    {
        print_char(franky[zoro]);
        zoro++;
    }
}

/**
 * print_char - writes the character c to stdout
 * @keros: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int print_char(char keros)
{
    static int zoro;
    static char tony[WRITE_BUF_SIZE];

    if (keros == BUF_FLUSH || zoro >= WRITE_BUF_SIZE)
    {
        write(1, tony, zoro);
        zoro = 0;
    }
    if (keros != BUF_FLUSH)
        tony[zoro++] = keros;
    return (1);
}

