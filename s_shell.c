#include "s_shell.h"

/**
 * s_shell - oprate shell command
 *
 * Return: On success 0.
 * On error, -1 is returned, and errno is set appropriately.
 */
int s_shell(void)
{
	char **command = NULL;

	_puts("s_shell$ ");

	command = get_Command();

	execut_Command(command);


	freeString(command);
	return (0);
}
