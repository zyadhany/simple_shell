#include "s_shell.h"

/**
 * _envp - print the enviroment variables
 *
 * Return: 0 at sucess 1 at filed
 */
int _envp(void)
{
	if (_sstrlen(info.command) != 1)
		return (1);

	print_list(info.envp);

	return (0);
}


/**
 * _getEnvp - get the index of enviroment variable
 * @var: variable to look at
 * Return: index of variable. On error, -1.
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

