#include "s_shell.h"

/**
 * execute_Command - execute given command
 * @command: command to execute
 *
 * Return: On success 0.
 * On error, 1.
 */
int execute_Command(char **command)
{

	/*replace first arg with path*/
	if (Get_path(&command[0]))
	{
		_puts("Command not found\n");
		return (1);
	}

	printf("%s\n", command[0]);
	
	/*fork and start new process with execve*/

	return (0);
}
