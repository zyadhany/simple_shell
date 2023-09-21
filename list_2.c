#include "s_shell.h"

/**
 * list_to_strings - convert list to string
 * @lis: given list
 * Return: pointer to array of string
 */
char **list_to_strings(list_t *lis)
{
	int n, i;
	char **str = NULL;
	list_t *tmp = lis;

	if (!lis)
		return (NULL);

	n = list_len(tmp);

	str = malloc(sizeof(char *) * (n + 1));

	for (i = 0; i <= n; i++)
		str[i] = NULL;

	for (i = 0; i < n; i++)
	{
		_strcpy(&(str[i]), tmp->str);
		if (!str[i])
		{
			freeString(str);
			return (NULL);
		}
		tmp = tmp->next;
	}

	return (str);
}

/**
 * add_node2 - adds a new node to a given list
 * @lis: given list
 * @str1: first element to add
 * @str2: second element to add
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
 * get_node_elem - get node with given value
 * @lis: given list
 * @str: given string
 * Return: pointer to node, NULL if not exits
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
 * get_node_index - gets index of node with given value
 * @lis: given list
 * @str: given string
 * Return: index of node
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
 * @lis: given list
 * @k: index of of node in specified list
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
