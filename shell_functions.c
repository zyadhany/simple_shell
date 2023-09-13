#include "s_shell.h"



/**
 * command_error - exit from shell
 * @error_massage: array of massage to displat.
 *
 */
void command_error(char *error_massage[])
{
	int i;

	_puts(info.argv[0]);
	_puts(": ");
	print_int(info.command_count);
	_puts(": ");
	_puts(info.command[0]);

	for (i = 0; error_massage[i]; i++)
	{
		_puts(": ");
		_puts(error_massage[i]);
	}

	putchar('\n');
}



/**
 * _exitShell - exit from shell
 *
 * Return: 0 at sucess 2 at filed
 */
int _exitShell(void)
{
	int exit_status = info.status;
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

		exit_status = _stoi(status) % 256;
	}

	freeString(info.command);
	exit(exit_status);
}

