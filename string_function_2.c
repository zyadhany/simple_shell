#include "s_shell.h"

/**
 * _strcpy - function copy string into another
 * @str1: string to copy at.
 * @str2: string to copy from.
 *
 */
void _strcpy(char **str1, char *str2)
{
	int n, i;

	n = _strlen(str2);

	if (!str1)
		return;

	free(*str1);
	*str1 = malloc(sizeof(char) * (n + 1));

	if (!(*str1))
		return;

	for (i = 0; i <= n; i++)
		(*str1)[i] = str2[i];

}

/**
 * _lcp - function calculate longest common prefix between 2 strings,
 * @str1: first string.
 * @str2: second string.
 *
 * Return: int represent lcp.
 */
int _lcp(char *str1, char *str2)
{
	int n = 0, i;

	if (!str1 || !str2)
		return (0);

	for (i = 0; str1[i] && str2[i]; i++)
	{
		if (str1[i] != str2[i])
			break;
		n++;
	}

	return (n);
}

/**
 * _appendStr - function append string to the end of string,
 * @str1: string appedn to.
 * @str2: string to append.
 *
 * Return: int represent lcp.
 */
void _appendStr(char **str1, char *str2)
{
	int n, m, i;
	char *s;

	if (!str1 || !str2)
		return;

	n = _strlen(*str1);
	m = _strlen(str2);
	s = malloc(sizeof(char) * (n + m + 1));

	for (i = 0; i < n; i++)
		s[i] = (*str1)[i];

	for (i = n; i < n + m; i++)
		s[i] = str2[i - n];

	s[n + m] = '\0';

	free(*str1);
	*str1 = s;
}
