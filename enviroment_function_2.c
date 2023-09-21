#include "s_shell.h"

/**
 * get_environ - sycn with envirment list
 * Return: array of strings represent enviromentt variables.
 */
char **get_environ(void)
{
	if (!info.environ || info.enviroment_changed)
	{
		freeString(info.environ);
		info.environ = list_to_strings(info.envp);
		info.enviroment_changed = 0;
	}

	return (info.environ);
}

/**
 * env_val - get value of enviroment variable.
 * @var: enviroment variable to find it's value
 * Return: string represent the value of varible, return NULL if not found.
 */
char *env_val(char *var)
{
	int index, n;
	char *val = NULL, *envar = NULL;

	index = _getEnvp(var);

	if (index == -1)
		return (NULL);

	n = _strlen(var);
	envar = get_node(info.envp, index);

	val = envar + n + 1;

	return (val);
}

/**
 * _getEnvp - gets the index of enviroment variable
 * @var: variable to look at
 * Return: index of variable. On error, -1
 */
int _getEnvp(char *var)
{
	int n, i = 0, j;
	list_t *tmp = info.envp;

	n = _strlen(var);

	while (tmp)
	{
		j = _lcp(tmp->str, var);
		if (j == n)
			if (tmp->str[j] == '=')
				return (i);
		i++;
		tmp = tmp->next;
	}

	return (-1);
}

/**
 * _envp - print the enviroment variables
 * Return: 0 at sucess 1 at filed
 */
int _envp(void)
{
	if (_sstrlen(info.command) != 1)
		return (1);

	info.STD = 1;
	print_list(info.envp);
	info.STD = 2;

	return (0);
}
