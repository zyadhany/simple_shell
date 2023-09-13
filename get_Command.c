#include "s_shell.h"


/**
 * _exitC - exit code on error
 * @str: string to free
 * Return: Nothing
 */
void _exitC(char *str)
{
	free(str);
	_putchar('\n');
	exit(info.status);
}

/**
 * get_Command - gets input from user
 * and separates it into several commands
 * or Command and flags/arguments
 *
 * Return: array of strings.
 */
char **get_Command(void)
{
	int n;
	size_t len = 0;
	char *input = NULL, dlm[3] = " \n";
	char **command = NULL;

	n = getline(&input, &len, stdin);

	if (n == -1)
		_exitC(input);

	if (_strcnt(input, dlm))
	{
		command = _strtok(input, dlm);
		if (!command)
			_exitC(input);
	}

	free(input);
	return (command);
}

