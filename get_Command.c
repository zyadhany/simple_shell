#include "s_shell.h"


/**
 * _exitC - exit code in error
 * @str: string to free
 *
 */
void _exitC(char *str)
{
	free(str);
	_putchar('\n');
	exit(1);
}

/**
 * get_Command - this function get input from user
 * sprate it to servral commands
 *
 * Return: array of strings.
 */
char **get_Command()
{
	int n;
	size_t len = 0;
	char *input = NULL, drl[3] = " \n";
	char **command = NULL;

	n = getline(&input, &len, stdin);

	if (n == -1)
		_exitC(input);

	if (_strcnt(input, drl))
	{
		command = _strtok(input, drl);
		if (!command)
			_exitC(input);
	}

	free(input);
	return (command);
}

