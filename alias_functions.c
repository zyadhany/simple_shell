#include "s_shell.h"

/**
 * put_alias - print an element of alias.
 * @alias_element: element to print.
 * Return: Nothing.
 */
void put_alias(list_t *alias_element)
{
	_puts(alias_element->str);
	_puts("='");
	_puts(alias_element->str2);
	_puts("'\n");
}

/**
 * print_alias - print all exiting alias.
 * Return: 0 at sucess 1 at filed.
 */
int print_alias(void)
{
	list_t *tmp = info.alias;

	while (tmp)
	{
		put_alias(tmp);
		tmp = tmp->next;
	}

	return (0);
}

/**
 * alias_read - read value in alias.
 * @var: var to read.
 *
 * Return: 0 at sucess 1 at filed.
 */
int alias_read(char *var)
{
	list_t *node = get_node_elem(info.alias, var);

	if (!node)
	{
		/*error massage*/
		_puts("alias: ");
		_puts(var);
		_puts(" not found\n");
		return (0);
	}

	put_alias(node);
	return (0);
}

/**
 * alias_write - write a new value in alias.
 * @elem: var and value to write.
 *
 * Return: 0 at sucess 1 at filed.
 */
int alias_write(char *elem)
{
	int index, i;
	char *var = NULL, *val = NULL;
	list_t *tmp;

	index = str_find(elem, '=');
	val = elem + index;

	var = malloc(sizeof(char) * index);

	if (!var)
		return (1);

	for (i = 0; i < index - 1; i++)
		var[i] = elem[i];

	var[index - 1] = '\0';

	tmp = add_node2(&info.alias, var, val);
	free(var);
	if (!tmp)
		return (1);
	return (0);
}

/**
 * alias_shell - control alias and arrange how it go
 *
 * Return: 0 at sucess 1 at filed
 */
int alias_shell(void)
{
	int i;

	if (!info.command[1])
	{
		print_alias();
		return (0);
	}

	for (i = 1; info.command[i]; i++)
	{
		if (!str_find(info.command[i], '='))
			alias_read(info.command[i]);
		else
			alias_write(info.command[i]);
	}

	return (0);
}
