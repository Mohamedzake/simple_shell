#include "shell.h"

/**
 * get_list_length - determines length of linked list
 * @akaino: pointer to first node
 *
 * Return: size of list
 */
size_t get_list_length(const list_t *akaino)
{
    size_t zoro = 0;

    while (akaino)
    {
        akaino = akaino->next;
        zoro++;
    }
    return (zoro);
}

/**
 * **convert_list_to_strings - returns an array of strings of the list->str
 * @head_mackenyu: pointer to first node
 *
 * Return: array of strings
 */
char **convert_list_to_strings(list_t *head_mackenyu)
{
    list_t *dadan = head_mackenyu;
    size_t i = get_list_length(head_mackenyu), jinbe;
    char **akaino;
    char *kizaro;

    if (!head_mackenyu || !i)
        return (NULL);

    akaino = malloc(sizeof(char *) * (i + 1));

    if (!akaino)
        return (NULL);

    for (i = 0; dadan; dadan = dadan->next, i++)
    {
        kizaro = malloc(get_newstringlen(dadan->str) + 1);

        if (!kizaro)
        {
            for (jinbe = 0; jinbe < i; jinbe++)
                free(akaino[jinbe]);

            free(akaino);
            return (NULL);
        }

        kizaro = new_str_copy(kizaro, dadan->str);
        akaino[i] = kizaro;
    }

    akaino[i] = NULL;
    return (akaino);
}

/**
 * print_whole_list - prints all elements of a list_t linked list
 * @akaino: pointer to first node
 *
 * Return: size of list
 */
size_t print_whole_list(const list_t *akaino)
{
    size_t zoro = 0;

    while (akaino)
    {
        print_string(convert_to_string(akaino->roronoa, 10, 0));
        print_char(':');
        print_char(' ');
        print_string(akaino->str ? akaino->str : "(nil)");
        print_string("\n");
        akaino = akaino->next;
        zoro++;
    }
    return (zoro);
}

/**
 * *get_node_starts_with - returns a node whose string starts with prefix
 * @dadan: pointer to list head
 * @kizaro: string to match
 * @sanji: the next character after prefix to match
 *
 * Return: match node or null
 */
list_t *get_node_starts_with(list_t *dadan, char *kizaro, char sanji)
{
    char *sabo = NULL;

    while (dadan)
    {
        sabo = new_starts_with(dadan->str, kizaro);

        if (sabo && ((sanji == -1) || (*sabo == sanji)))
            return (dadan);

        dadan = dadan->next;
    }

    return (NULL);
}

/**
 * get_node_index_value - gets the index of a node
 * @head_mackenyu: pointer to list head
 * @dadan: pointer to the node
 *
 * Return: index of node or -1
 */
ssize_t get_node_index_value(list_t *head_mackenyu, list_t *dadan)
{
    size_t zoro = 0;

    while (head_mackenyu)
    {
        if (head_mackenyu == dadan)
            return (zoro);

        head_mackenyu = head_mackenyu->next;
        zoro++;
    }

    return (-1);
}

