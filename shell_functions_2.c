#include "s_shell.h"

/**
 * _getcwd - change current director
 * @str: string to put path
 * Return: 0 at sucess -1 at filed
 */
int _getcwd(char **str)
{
	size_t size = 0;
	char *buff = NULL;

	if (!str)
		return (-1);

	*str = getcwd(buff, size);

	if (!(*str))
	{
		free(*str);
		*str = NULL;
		return (-1);
	}

	return (0);
}

/**
 * _cd - change current director
 * Return: 0 at sucess 1 at filed
 */
int _cd(void)
{
	int len, status;
	char *path = NULL,  *prev = NULL;

	if (_getcwd(&prev) == -1)
		return (1);
	len = _sstrlen(info.command);
	if (len == 1)
		status = chdir(env_val("HOME"));
	else if (_strcomp("-", info.command[1]) == 0)
	{
		status = chdir(info.parent_dir);
		info.STD = 1;
		_puts(info.parent_dir);
		_putchar('\n');
		info.STD = 2;
	}
	else
		status = chdir(info.command[1]);
	if (!status)
	{
		_strcpy(&info.parent_dir, prev);
		free(prev);
	}
	if (!status)
	{
		if (_getcwd(&path) == -1)
			return (1);
		_setenv("PWD", path);
		info.enviroment_changed = 1;
		free(path);
	}
	else
		cd_error_massage();

	return (status);
}

/**
 * Buff_Flush - flush the buffer
 * Return: 0 at sucess 1 at filed
 */
int Buff_Flush(void)
{
	info.buffer_index = 0;
	return (0);
}

/**
 * _exitS - exit code on error
 * Return: Nothing
 */
void _exitS(void)
{
	if (isatty(fileno(stdin)) && !info.exit)
		_putchar('\n');
	FreeInfo();
	exit(info.status);
}

/**
 * _exitShell - exit from shell
 * Return: 0 at sucess 2 at filed
 */
int _exitShell(void)
{
	char *status = info.command[1];
	char *error_message[3] = {"Illegal number", NULL, NULL};

	error_message[1] = status;

	if (status)
	{
		if (!_isInt(status))
		{
			command_error(error_message);
			return (2);
		}

		if (_strlen(status) > 10 || _stoi(status) > __INT32_MAX__)
		{
			command_error(error_message);
			return (2);
		}

		info.status = _stoi(status) % 256;
	}

	info.exit = 1;
	_exitS();
	return (0);
}
