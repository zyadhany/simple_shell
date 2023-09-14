#include "s_shell.h"

/**
 * _sstrlen - gets length of a array of strings
 * @str: string whose length is needed
 * Return: length of given string.
 */
int _sstrlen(char **str)
{
	int n = 0;

	if (str)
		while ((*str)[n])
			n++;

	return (n);
}
