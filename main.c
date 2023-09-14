#include "s_shell.h"


int main(int argc, char *argv[]);
struct INFO info = INFO_INIT;

/**
 * main - Entry point
 * @argc: number of argument
 * @argv: array of argument
 *
 * Return: 0 On success
 */
int main(int argc, char *argv[])
{
	info.argv = argv;
	info.argc = argc;
	set_fuction();

	signal(SIGINT, SIG_IGN);

	do {
		s_shell();
		info.command_count++;
	} while (1);

	return (0);
}
