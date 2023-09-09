#include "s_shell.h"


/**
 * main - entry point
 *
 * Return: On success, 0.
 */

/*int argc, char *argv[], char *env[]*/

int main(void)
{
	signal(SIGINT, SIG_IGN);

	do {
		s_shell();
	} while (1);

	return (0);
}
