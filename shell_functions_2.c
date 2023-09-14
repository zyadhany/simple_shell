#include "s_shell.h"


/**
 * _cd - change current director
 *
 * Return: 0 at sucess 1 at filed
 */
int _cd(void)
{
	return (1);
}


/**
 * Buff_Flush - flush the buffer
 *
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
 *
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


