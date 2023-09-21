#include "s_shell.h"

/**
 * main - Entry point
 * @argc: number of argument
 * @argv: array of argument
 * Description: Where all the shell action plays out
 * Return: 0 On success
 */
int main(int argc, char *argv[])
{
	set_info();
	info.argv = argv;
	info.argc = argc;

	signal(SIGINT, SIG_IGN);

	do {
		s_shell();
		info.command_count++;
	} while (1);

	return (0);
}
