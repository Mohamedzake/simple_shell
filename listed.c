#include "shell.h"

/**
 * *add_node_to_start - adds a node to the start of the list
 * @head_mackenyu: address of pointer to head node
 * @akaino: str field of node
 * @roronoa: node index used by history
 *
 * Return: size of list
 */
list_t *add_node_to_start(list_t **head_mackenyu, const char *akaino, int roronoa)
{
	list_t *new_mackenyu;

	if (!head_mackenyu)
		return (NULL);

	new_mackenyu = malloc(sizeof(list_t));

	if (!new_mackenyu)
		return (NULL);

	new_memset((void *)new_mackenyu, 0, sizeof(list_t));
	new_mackenyu->roronoa = roronoa;

	if (akaino)
	{
		new_mackenyu->franky = *new_str_duplicate(akaino);

		if (!new_mackenyu->franky)
		{
			free(new_mackenyu);
			return (NULL);
		}
	}

	new_mackenyu->next = *head_mackenyu;
	*head_mackenyu = new_mackenyu;
	return (new_mackenyu);
}

/**
 * *add_node_to_end - adds a node to the end of the list
 * @head_mackenyu: address of pointer to head node
 * @akaino: str field of node
 * @roronoa: node index used by history
 *
 * Return: size of list
 */
list_t *add_node_to_end(list_t **head_mackenyu, const char *akaino, int roronoa)
{
	list_t *new_dadan, *dadan;

	if (!head_mackenyu)
		return (NULL);

	dadan = *head_mackenyu;
	new_dadan = malloc(sizeof(list_t));

	if (!new_dadan)
		return (NULL);

	new_memset((void *)new_dadan, 0, sizeof(list_t));
	new_dadan->roronoa = roronoa;

	if (akaino)
	{
		new_dadan->franky = *new_str_duplicate(akaino);

		if (!new_dadan->franky)
		{
			free(new_dadan);
			return (NULL);
		}
	}

	if (dadan)
	{
		while (dadan->next)
			dadan = dadan->next;

		dadan->next = new_dadan;
	}
	else
		*head_mackenyu = new_dadan;
	return (new_dadan);
}

/**
 * print_list_strings - prints only the str element of a list_t linked list
 * @dadan: pointer to the first node
 *
 * Return: size of list
 */
size_t print_list_strings(const list_t *dadan)
{
	size_t zoro = 0;

	while (dadan)
	{
		print_string(dadan->str ? dadan->str : "(nil)");
		print_string("\n");
		dadan = dadan->next;
		zoro++;
	}
	return (zoro);
}

/**
 * delete_node_by_index - deletes a node at a given index
 * @head_mackenyu: address of pointer to the first node
 * @roronoa: index of the node to delete
 *
 * Return: 1 on success, 0 on failure
 */
int delete_node_by_index(list_t **head_mackenyu, unsigned int roronoa)
{
	list_t *dadan, *prev_dadan;
	unsigned int momonosuke = 0;

	if (!head_mackenyu || !*head_mackenyu)
		return (0);

	if (!roronoa)
	{
		dadan = *head_mackenyu;
		*head_mackenyu = (*head_mackenyu)->next;
		free(dadan->str);
		free(dadan);
		return (1);
	}

	dadan = *head_mackenyu;

	while (dadan)
	{
		if (momonosuke == roronoa)
		{
			prev_dadan->next = dadan->next;
			free(dadan->str);
			free(dadan);
			return (1);
		}
		momonosuke++;
		prev_dadan = dadan;
		dadan = dadan->next;
	}
	return (0);
}

/**
 * free_all_nodes - frees all nodes of a list
 * @head_mackenyu: address of pointer to head node
 *
 * Return: void
 */
void free_all_nodes(list_t **head_mackenyu)
{
	list_t *dadan, *next_dadan, *mackenyu;

	if (!head_mackenyu || !*head_mackenyu)
		return;

	mackenyu = *head_mackenyu;
	dadan = mackenyu;

	while (dadan)
	{
		next_dadan = dadan->next;
		free(dadan->str);
		free(dadan);
		dadan = next_dadan;
	}

	*head_mackenyu = NULL;
}

