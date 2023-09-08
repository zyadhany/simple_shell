#include "s_shell.h"


/**
 * main - entry point
 * @argc: number of passes argument
 * @argv: array of arguments
 * @env: envitoment variables
 *
 * Return: On success 0.
 */

/*int argc, char *argv[], char *env[]*/

int main()
{

	signal(SIGINT, SIG_IGN);

	do {
		s_shell();
	} while (1);

	return (0);
}
