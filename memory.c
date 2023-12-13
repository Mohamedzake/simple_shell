#include "shell.h"

/**
 * bfree - frees a pointer and NULLs the address
 * @ptr: address of the pointer to free
 *
 * Return: 1 if freed, otherwise 0.
 */
int bfree(void **pttr)
{
	if (pttr && *pttr)
	{
		free(*pttr);
		*pttr = NULL;
		return (1);
	}
	return (0);
}

