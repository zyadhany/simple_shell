#include "s_shell.h"


/**
 * _exit - exit code in error
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
	int i = 0;

	size_t len = 0, n;
	char *input = NULL, s[3] = " \n";
	char **command = NULL;

	n = getline(&input, &len, stdin);

	if (n == -1)
		_exitC(input);

	if (_strcnt(input, s))
	{
		command = _strtok(input, s);
		if (!command)
			_exitC(input);
	}

	free(input);
	return (command);
}

