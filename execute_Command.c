#include "s_shell.h"

/**
 * execute_Command - executes a given command
 * Return: On success, 0.
 * On error, 1.
 */
int execute_Command(void)
{
	int id, i;
	char *error_message[3] = {"not found", NULL};

	for (i = 0; info.functions[i].name; i++)
		if (_strcomp(info.command[0], info.functions[i].name) == 0)
			return (info.functions[i].func());


	/*Replace first argument with its full path*/
	if (Get_path(&info.command[0]))
	{
		command_error(error_message);
		return (127);
	}

	id = fork();

	if (id == -1)
	{
		info.status = 1;
		_exitS();
	}


	if (id == 0)
	{
		execve(info.command[0], info.command, get_environ());
		info.status = 1;
		info.exit = 1;
		_exitS();
	}
	waitpid(id, &info.status, 0);

	return (WEXITSTATUS(info.status));
}
