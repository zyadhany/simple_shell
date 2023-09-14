#include "s_shell.h"


/**
 * print_list - print list
 * @lis: given list
 *
 * Return: size of list.
 */

size_t print_list(const list_t *lis)
{
	int n = 0;

	while (lis)
	{
		_puts(lis->str);
		_putchar('\n');
		n++;
		lis = lis->next;
	}

	return (n);
}


/**
 * list_len - get lenght of given list.
 * @lis: given list.
 *
 * Return: size of list.
 */

size_t list_len(const list_t *lis)
{
	int n = 0;

	while (lis)
	{
		n++;
		lis = lis->next;
	}

	return (n);
}


/**
 * add_node - add node to the list.
 * @lis: given list.
 * @s: added element.
 *
 * Return: pointer to list.
 */

list_t *add_node(list_t **lis, char *s)
{
	list_t *tmp = malloc(sizeof(list_t)), *at = *lis;

	if (!tmp)
		return (NULL);

	tmp->str = NULL;
	_strcpy(&tmp->str, s);
	tmp->next = NULL;

	if (tmp->str == NULL)
	{
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
 * delete_node_at_index - delete index of node in list
 * @lis: given list
 * @k: index of list
 *
 * Return: pointer to list.
 */

int delete_node_at_index(list_t **lis, int k)
{
	int i = 0;
	list_t *X = *lis, *tmp;

	if (k == 0)
	{
		if (!X)
			return (-1);
		tmp = X->next;
		free(X->str);
		free(X);
		*lis = tmp;
		return (1);
	}

	for (i = 0; i < k - 1; i++)
	{
		if (!X)
			return (-1);
		X = X->next;
	}

	if (!X)
		return (-1);
	if (!X->next)
		return (-1);

	tmp = X->next->next;
	free(X->next->str);
	free(X->next);
	X->next = tmp;

	return (1);
}


/**
 * free_list - free list
 * @lis: given list
 *
 * Return: free all element of list
 */

void free_list(list_t *lis)
{
	if (lis)
	{
		free_list(lis->next);
		free(lis->str);
		free(lis);
	}
}

