#include "s_shell.h"

/**
 * _isInt - checks if a string contains integer or not
 * @s: string to check
 * Return: 1 if integer, 0 otherwise
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
 * int_to_string - convert from int to string
 * @n: integer to convert
 * Return: string represent an int
 */
char *int_to_string(int n)
{
	int i;
	static char s[32];

	if (n == 0)
	{
		s[0] = '0', i = 1;
	}
	else
	{
		for (i = 0; n; i++)
		{
			s[i] = '0' + n % 10;
			n /= 10;
		}
	}

	s[i] = '\0';

	_reverse(s);
	return (s);
}

/**
 * _stoi - convert string to integer
 * @s: string to convert
 * Return: int represent string after convert.
 */
u_int64_t _stoi(char *s)
{
	u_int64_t n = 0, i;

	for (i = 0; s[i] ; i++)
		n = (n * 10 + s[i] - '0') % MODE;

	return (n);
}
