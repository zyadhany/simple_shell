#include "s_shell.h"

int set_info(void);
struct INFO info;

/**
 * set_info - set up info.
 *
 * Return: 0 at sucess, 1 fail.
 */
int set_info(void)
{
	int stats = 0;

	info.STD = 2;
	info.command_count = 1;
	info.exit = info.enviroment_changed = 0;
	info.status = info.argc = info.buffer_index = 0;
	info.argv = info.command = info.environ = NULL;
	info.commands_To_run = NULL;
	info.input = info.buffer = NULL;
	info.envp = info.alias = NULL;
	info.functions[0].name = NULL;
	info.functions[1].func = NULL;

	stats += _getcwd(&info.parent_dir);
	stats += set_fuction();
	stats += set_envp();
	stats += set_buffer();

	if (stats < 0)
		_exitS();

	return (0);
}


/**
 * set_fuction - set fuctions into info
 *
 * Return: 0 at sucess, -1 fail.
 */
int set_fuction(void)
{
	info.functions[0].name = "exit";
	info.functions[0].func = &_exitShell;

	info.functions[1].name = "cd";
	info.functions[1].func = &_cd;

	info.functions[2].name = "env";
	info.functions[2].func = &_envp;

	info.functions[3].name = "setenv";
	info.functions[3].func = &_Mysetenv;

	info.functions[4].name = "unsetenv";
	info.functions[4].func = &_Myunsetenv;

	info.functions[5].name = "alias";
	info.functions[5].func = &alias_shell;

	info.functions[6].name = NULL;
	info.functions[6].func = NULL;

	return (0);
}


/**
 * set_buffer - set up buffer for memory mangment.
 *
 * Return: 0 at sucess, -1 fail.
 */
int set_buffer(void)
{
	info.buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));

	if (!info.buffer)
		return (-1);

	info.buffer[BUFFER_SIZE] = '\0';

	return (0);
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

	_putchar('\n');
}

/**
 * FreeInfo - free all alocated memory in info.
 *
 */
void FreeInfo(void)
{
	free(info.input);
	free(info.buffer);
	free(info.parent_dir);
	free_list(info.envp);
	free_list(info.alias);
	free_2d_String(info.commands_To_run);
	freeString(info.environ);
	if (!info.exit)
		freeString(info.command);
}
