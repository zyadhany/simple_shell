#include "s_shell.h"

/**
 * get_input - gets input from user
 * Return: 0 on sucess, -1 on failure
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
 * check_comments - check if there is comment or not
 * @str: array of strting to check
 * Return: 1 if present, 0 if not
 */
int check_comments(char **str)
{
	int i;

	if (!str)
		return (0);

	for (i = 0; str[i]; i++)
	{
		if (str[i][0] == '#')
		{
			while (str[i])
			{
				free(str[i]);
				str[i] = NULL;
				i++;
			}
			return (1);
		}

	}

	return (0);
}

/**
 * break_command - break command into several commands
 * Return: 0 at sucess, -1 fail
 */
int break_command(void)
{
	int n, i, j;
	char dlm1[3] = ";\n\0";
	char dlm2[3] = " \n\0";

	if (!_strcnt(info.input, dlm2))
		return (-1);

	n = _strcnt(info.input, dlm1);

	info.command = _strtok(info.input, dlm1);
	if (!info.command)
		_exitS();

	info.commands_To_run = malloc(sizeof(char **) * (1 + n));

	for (i = 0; i <= n; i++)
		info.commands_To_run[i] = NULL;

	for (i = 0; i < n; i++)
	{
		info.commands_To_run[i] = _strtok(info.command[i], dlm2);
		if (!info.commands_To_run[i])
			_exitS();
		if (check_comments(info.commands_To_run[i]))
		{
			if (!info.commands_To_run[i][0])
			{
				freeString(info.commands_To_run[i]);
				info.commands_To_run[i] = NULL;
			}
			break;
		}
		for (j = 0; info.commands_To_run[i][j]; j++)
			if (replace_to_env(&info.commands_To_run[i][j]) == -1)
				_exitS();
	}

	freeString(info.command);
	info.command = NULL;
	return (0);
}

/**
 * get_Command - gets input from user
 * and separates it into several commands
 * or Command and flags/arguments
 * Return: array of strings
 */
int **get_Command(void)
{
	get_input();
	break_command();

	return (0);
}
