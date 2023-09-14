#include "s_shell.h"

/**
 * s_shell - carries out shell coomand operations
 *
 * Return: On success, 0
 * On error, -1. errno is set appropriately
 */
int s_shell(void)
{
	info.command = NULL;

	if (isatty(fileno(stdin)))
		_puts(PROMPT);

	info.command = get_Command();

	if (info.command)
		info.status = execute_Command();


	freeString(info.command);
	return (0);
}
