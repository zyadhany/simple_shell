#include "s_shell.h"

/**
 * _isInt - check if string is int or no.
 * @s: string to check.
 *
 * Return: 1 if it is int, 0 otherwise.
 */
int _isInt(char *s)
{
	int i;

	if (!s)
		return (0);

	for (i = 0; s[i]; i++)
		if (s[i] < '0' || s[i] > '9')
			return (0);

	return (1);
}


/**
 * _stoi - convert string to int.
 * @s: string to convert.
 *
 * Return: int represent string after convert.
 */
u_int64_t _stoi(char *s)
{
	u_int64_t n = 0, i;

	for (i = 0; s[i] ; i++)
		n = (n * 10 + s[i] - '0') % MODE;

	return (n);
}
