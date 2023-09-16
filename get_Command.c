#include "s_shell.h"


/**
 * get_input - gets input from user
 * 
 * Return: 0 at sucess, -1 fail.
 */
int get_input(void)
{
	int n, len;

	n = _getline(&info.input, &len, 0);

	if (n == -1)
		_exitS();

	return (0);
}

/**
 * get_input - gets input from user
 * 
 * Return: 0 at sucess, -1 fail.
 */
int break_command(void)
{
	int n, len;

	n = _getline(&info.input, &len, 0);

	if (n == -1)
		_exitS();

	return (0);
}

/**
 * get_Command - gets input from user
 * and separates it into several commands
 * or Command and flags/arguments
 *
 * Return: array of strings.
 */
int **get_Command(void)
{
	char dlm[3] = " \n\0";
	char **command = NULL;

	get_input();

	if (_strcnt(info.input, dlm))
	{
		command = _strtok(info.input, dlm);
		if (!command)
			_exitS();
	}

	info.command = command;
	return (0);
}

