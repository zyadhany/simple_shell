#include "s_shell.h"


/**
 * get_node - get value of node at given index
 * @lis: given list
 * @k: index of list
 *
 * Return: value of the node.
 */

char *get_node(listint_t *lis, int k)
{

	int i = 0;

	for (i = 0; i <= k; i++)
	{
		if (!lis)
			return (NULL);
		if (i == k)
			return (lis);
		lis = lis->next;
	}

	return (NULL);
}
