#include "s_shell.h"

/**
 * Get_path - reblace command with it path
 * @coma: command to get path for
 *
 * Return: On success 0.
 * On error, 1.
 */
int Get_path(char **coma)
{
	int index, n;
	char var[] = "PATH",
		 drl[4] = "=:\n",
		 **path = NULL;

	index = _getEnvp(var);

	if (index == -1)
		return (1);

	path = _strtok(environ[index], drl);
	_strcpy(&path[0], *coma);

	n = path_check(path, *coma);

	if (n == -1)
	{
		freeString(path);
		return (1);
	}

	_strcpy(coma, path[n]);

	freeString(path);
	return (0);
}

/**
 * _getEnvp - get the index of enviroment variable
 * @var: var to look at
 *
 * Return: index of variable.
 * On error, -1.
 */
int _getEnvp(char *var)
{
	int n, i, j;

	n = _strlen(var);

	for (i = 0; environ[i] ; i++)
	{
		j = _lcp(environ[i], var);
		if (j == n && environ[i][j] == '=')
			return (i);
	}

	return (-1);
}

/**
 * path_check - check which of these path is valid
 * @path: array of paths
 * @coma: command to check
 *
 * Return: index of valid path.
 * On error, -1.
 */
int path_check(char **path, char *coma)
{
	int i;
	struct stat st;

	if (!path || !coma)
		return (-1);

	for (i = 1; path[i] ; i++)
	{
		_appendStr(&path[i], "/");
		_appendStr(&path[i], coma);
	}

	for ( i = 0; path[i] ; i++)
		if (!stat(path[i], &st))
			return (i);
		
	return (-1);
}
