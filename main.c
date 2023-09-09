#include "s_shell.h"


/**
 * main - Entry point
 *
 * Return: 0 On success
 */

/*int argc, __attribute__((unused))char *argv[], char *env[]*/

int main(void)
{
	signal(SIGINT, SIG_IGN);

	do {
		s_shell();
	} while (1);

	return (0);
}
