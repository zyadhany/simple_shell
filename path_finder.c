#include "s_shell.h"

/**
 * Get_path - Replaces command with its full path
 * @command: command to get path for
 * Return: On success 0. On failure, 1
 */
int Get_path(char **command)
{
	int index, n;
	char var[] = "PATH",
		 dlm[4] = "=:\n",
		 **path = NULL;

	index = _getEnvp(var);

	if (index == -1)
		return (1);

	path = _strtok(get_node(info.envp, index), dlm);
	_strcpy(&path[0], *command);

	n = path_check(path, *command);

	if (n == -1)
	{
		freeString(path);
		return (1);
	}

	_strcpy(command, path[n]);

	freeString(path);
	return (0);
}


/**
 * path_check - checks which of the paths is valid
 * @path: array of paths
 * @command: command to look for
 * Return: index of valid path. On error, -1
 */
int path_check(char **path, char *command)
{
	int i;
	struct stat st;

	if (!path || !command)
		return (-1);

	for (i = 1; path[i] ; i++)
	{
		_appendStr(&path[i], "/");
		_appendStr(&path[i], command);
	}

	for (i = 0; path[i] ; i++)
		if (!stat(path[i], &st))
			return (i);

	return (-1);
}

