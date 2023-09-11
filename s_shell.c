#include "s_shell.h"

/**
 * s_shell - Operates shell command
 *
 * Return: On success, 0.
 * On error, -1. errno is set appropriately.
 */
int s_shell(struct INFO info)
{

	_puts("s_shell$ ");

	info.command = get_Command();

	if (info.command)
		execute_Command(info);

	freeString(info.command);
	return (0);
}
