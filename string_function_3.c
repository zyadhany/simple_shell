#include "s_shell.h"

/**
 * _sstrlen - gets the length of an array of strings
 * @str: string whose length is needed
 * Return: length of given string
 */
int _sstrlen(char **str)
{
	int n = 0;

	if (str)
		while (str[n])
			n++;

	return (n);
}

/**
 * free_2d_String - frees an 2d array of strings
 * @str: array to free
 *
 */
void free_2d_String(char ***str)
{
	int i = 0;

	if (!str)
		return;

	while (str[i])
		freeString(str[i++]);
	
	free(str);
}
