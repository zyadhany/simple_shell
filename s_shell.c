#include "s_shell.h"

/**
 * s_shell - carries out shell coomand operations
 * Description: This function feeds main
 * Return: On success, 0
 * On error, -1. errno is set appropriately
 */
int s_shell(void)
{
	int i;

	info.command = NULL;
	info.commands_To_run = NULL;

	if (isatty(fileno(stdin)))
		_puts(PROMPT);

	get_Command();

	if (!info.commands_To_run)
		return (0);

	for (i = 0; info.commands_To_run[i]; i++)
	{
		info.command = info.commands_To_run[i];
		info.status = execute_Command();
	}

	free_2d_String(info.commands_To_run);
	return (0);
}
