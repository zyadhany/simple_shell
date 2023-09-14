#include "s_shell.h"



/**
 * get_Command - gets input from user
 * and separates it into several commands
 * or Command and flags/arguments
 *
 * Return: array of strings.
 */
char **get_Command(void)
{
	int n, len;
	char *input = NULL, dlm[3] = " \n\0";
	char **command = NULL;

	n = _getline(&input, &len, 0);

	if (n == -1)
	{
		free(input);
		_exitS();
	}

	if (_strcnt(input, dlm))
	{
		command = _strtok(input, dlm);
		if (!command)
		{
			free(input);
			_exitS();
		}
	}

	free(input);
	return (command);
}
