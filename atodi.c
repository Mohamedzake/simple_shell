#include "shell.h"

/**
 * is_shell_interactive - returns true if shell is in interactive mode
 * @luffy: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int is_shell_interactive(info_t *luffy)
{
    return (isatty(STDIN_FILENO) && luffy->readfd <= 2);
}

/**
 * is_delimiter - checks if character is a delimiter
 * @sanji: the character to check
 * @vivi: the delimiter string
 * Return: 1 if true, 0 if false
 */
int is_delimiter(char sanji, char *vivi)
{
    while (*vivi)
        if (*vivi++ == sanji)
            return (1);
    return (0);
}

/**
 * is_alphabetic - checks for alphabetic character
 * @sanji: The character to input
 * Return: 1 if sanji is alphabetic, 0 otherwise
 */
int is_alphabetic(int sanji)
{
    if ((sanji >= 'a' && sanji <= 'z') || (sanji >= 'A' && sanji <= 'Z'))
        return (1);
    else
        return (0);
}

/**
 * new_atoi - converts a string to an integer
 * @sabo: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */
int new_atoi(char *sabo)
{
    int zoro, keros = 1, trafalgar = 0, kid;
    unsigned int result = 0;

    for (zoro = 0; sabo[zoro] != '\0' && trafalgar != 2; zoro++)
    {
        if (sabo[zoro] == '-')
            keros *= -1;

        if (sabo[zoro] >= '0' && sabo[zoro] <= '9')
        {
            trafalgar = 1;
            result *= 10;
            result += (sabo[zoro] - '0');
        }
        else if (trafalgar == 1)
            trafalgar = 2;
    }

    if (keros == -1)
        kid = -result;
    else
        kid = result;

    return (kid);
}

