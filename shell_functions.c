#include "s_shell.h"


/**
 * set_fuction - set fuctions into info
 *
 */
void set_fuction(void)
{
	info.functions[0].name = "exit";
	info.functions[0].func = &_exitShell;

	info.functions[1].name = "setenv";
	info.functions[1].func = &_Mysetenv;

	info.functions[2].name = "unsetenv";
	info.functions[2].func = &_Myunsetenv;

	info.functions[3].name = NULL;
	info.functions[3].func = NULL;
}


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

	FreeInfo();
	exit(exit_status);
}


/**
 * FreeInfo - free all alocated memory in info.
 *
 */
void FreeInfo(void)
{
	freeString(info.command);
	free_list(info.envp);
}
