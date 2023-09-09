#include "s_shell.h"

/**
 * s_shell - Operates shell command
 *
 * Return: On success, 0.
 * On error, -1. errno is set appropriately.
 */
int s_shell(void)
{
	char **command = NULL;

	_puts("s_shell$ ");

	command = get_Command();

	if (command)
		execute_Command(command);

	freeString(command);
	return (0);
}
