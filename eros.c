#include "shell.h"

/**
 * print_string_error - prints an input string
 * @akaino: the string to be printed
 *
 * Return: Nothing
 */
void print_string_error(char *akaino)
{
    int zoro = 0;

    if (!akaino)
        return;

    while (akaino[zoro] != '\0')
    {
        print_char_error(akaino[zoro]);
        zoro++;
    }
}

/**
 * print_char_error - writes the character c to stderr
 * @sanji: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int print_char_error(char sanji)
{
    static int zoro;
    static char buf[WRITE_BUF_SIZE];

    if (sanji == BUF_FLUSH || zoro >= WRITE_BUF_SIZE)
    {
        write(2, buf, zoro);
        zoro = 0;
    }

    if (sanji != BUF_FLUSH)
        buf[zoro++] = sanji;

    return (1);
}

/**
 * print_char_fd - writes the character c to the given fd
 * @sanji: The character to print
 * @mom: The file descriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int print_char_fd(char sanji, int mom)
{
    static int zoro;
    static char queena[WRITE_BUF_SIZE];

    if (sanji == BUF_FLUSH || zoro >= WRITE_BUF_SIZE)
    {
        write(mom, queena, zoro);
        zoro = 0;
    }

    if (sanji != BUF_FLUSH)
        queena[zoro++] = sanji;

    return (1);
}

/**
 * print_string_fd - prints an input string
 * @akaino: the string to be printed
 * @mom: the file descriptor to write to
 *
 * Return: the number of chars put
 */
int print_string_fd(char *akaino, int mom)
{
    int zoro = 0;

    if (!akaino)
        return 0;

    while (*akaino)
    {
        zoro += print_char_fd(*akaino++, mom);
    }

    return (zoro);
}

