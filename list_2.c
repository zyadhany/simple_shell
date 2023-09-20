#include "s_shell.h"

/**
 * add_node2 - adds a new node to a given list
 * @lis: list given
 * @str1: first added element
 * @str2: second added element
 * Return: pointer to list
 */
list_t *add_node2(list_t **lis, char *str1, char *str2)
{
	list_t *tmp = malloc(sizeof(list_t)), *at = *lis;

	if (!tmp)
		return (NULL);

	tmp->str = NULL;
	tmp->str2 = NULL;
	_strcpy(&tmp->str, str1);
	_strcpy(&tmp->str2, str2);
	tmp->next = NULL;

	if (tmp->str == NULL)
	{
		free(tmp);
		return (NULL);
	}

	if (tmp->str2 == NULL)
	{
		free(tmp->str);
		free(tmp);
		return (NULL);
	}

	if (!*lis)
	{
		*lis = tmp;
		return (*lis);
	}

	while (at->next)
	{
		at = at->next;
	}

	at->next = tmp;

	return (*lis);
}

/**
 * get_node_elem - get node with given value.
 * @lis: list given
 * @str: given string.
 *
 * Return: pointer to node, NULL if not exits.
 */

list_t *get_node_elem(list_t *lis, char *str)
{
	while (lis)
	{
		if (!_strcomp(lis->str, str))
			return (lis);
		lis = lis->next;
	}

	return (NULL);
}

/**
 * get_node_index - gets index of node with given value.
 * @lis: list given
 * @str: given string.
 *
 * Return: index of node.
 */

int get_node_index(list_t *lis, char *str)
{
	int i = 0;

	while (lis)
	{
		if (!_strcomp(lis->str, str))
			return (i);
		i++;
		lis = lis->next;
	}

	return (-1);
}

/**
 * get_node - gets value of node at a given index
 * @lis: list given
 * @k: index of of node in list
 * Return: value of the node
 */

char *get_node(list_t *lis, int k)
{
	int i = 0;

	for (i = 0; i <= k; i++)
	{
		if (!lis)
			return (NULL);
		if (i == k)
			return (lis->str);
		lis = lis->next;
	}

	return (NULL);
}
