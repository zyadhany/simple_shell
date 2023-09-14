#include "s_shell.h"


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
