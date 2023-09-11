#include "s_shell.h"


/**
 * main - Entry point
 *
 * Return: 0 On success
 */

/*, char *env[]*/

int main(__attribute__((unused)) int argc, char *argv[])
{
	struct INFO info = INFO_INIT;

	info.argv = argv;

	signal(SIGINT, SIG_IGN);

	do {
		s_shell(info);
		info.command_count++;
	} while (1);

	return (0);
}
