#include "s_shell.h"

/**
 * execute_Command - executes a given command
 * @command: command to execute
 * Return: On success, 0.
 * On error, 1.
 */
int execute_Command(struct INFO info)
{
	int id;

	if (_strcomp(info.command[0], "exit") == 0)
	{
		freeString(info.command);
		exit(1);
	}

	/*Replace first argument with its full path*/
	if (Get_path(&info.command[0]))
	{
		_puts(info.argv[0]);
		_puts(": ");
		print_int(info.command_count);
		_puts(": ");
		_puts(info.command[0]);
		_puts(": not found\n");
		return (1);
	}

	id = fork();

	if (id == 0)
		execve(info.command[0], info.command, environ);

	wait(&id);

	return (0);
}
