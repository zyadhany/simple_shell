#include "s_shell.h"

/**
 * cd_error_massage - print error message of cd.
 *
 * Return: Nothing.
 */
void cd_error_massage(void)
{
		_puts(info.argv[0]);
		_puts(": ");
		print_int(info.command_count);
		_puts(": ");
		_puts(info.command[0]);
		_puts(": can't cd to ");
		_puts(info.command[1]);
		_putchar('\n');
}
