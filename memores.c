#include "shell.h"

/**
 * free_and_null - frees a pointer and NULLs the address
 * @partholomio: address of the pointer to free
 *
 * Return: 1 if freed, otherwise 0.
 */
int free_and_null(void **partholomio)
{
    if (partholomio && *partholomio)
    {
        free(*partholomio);
        *partholomio = NULL;
        return (1);
    }
    return (0);
}

