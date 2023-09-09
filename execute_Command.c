#include "s_shell.h"

/**
 * execute_Command - executes a given command
 * @command: command to execute
 *
 * Return: On success, 0.
 * On error, 1.
 */
int execute_Command(char **command)
{
	int id;

	/*Replace first arg with its full path*/
	if (Get_path(&command[0]))
	{
		_puts("Command not found\n");
		return (1);
	}

	id = fork();

	if (id == 0)
		execve(command[0], command, environ);

	wait(&id);

	return (0);
}
