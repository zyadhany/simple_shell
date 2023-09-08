#include "s_shell.h"

/**
 * _strlen - get leanght of string.
 * @str: string to get it's lenght.
 *
 * Return: lenght of given string.
 */
int _strlen(char *str)
{
	int n = 0;

	if (str)
		while (str[n])
			n++;

	return (n);
}

/**
 * str_find - break string into servrall strings
 * @str: string to look at
 * @c: chat want to find in string
 *
 * Return: 1 if found char, 0 otherwise.
 */
int str_find(char *str, char c)
{
	int i;

	for (i = 0; str[i] ; i++)
		if (str[i] == c)
			return (1);

	return (0);
}

/**
 * _strcnt - return number of string after break
 * @str: string to break.
 * @drl: what to break at.
 *
 * Return: array of strings
 */
int _strcnt(char *str, char *drl)
{
	int n = 0, i, at = 0;

	if (!str)
		return (0);

	for (i = 0; str[i] ; i++)
	{
		if (!str_find(drl, str[i]))
			continue;
		if (i != at)
			n++;
		at = i + 1;
	}

	if (i != at)
		n++;

	return (n);
}

/**
 * _strtok - break string into servrall strings
 * @str: string to be break
 * @drl: what to break in
 *
 * Return: array of strings
 */
char **_strtok(char *str, char *drl)
{
	int n = 0, i, j, at = 0;
	char **s;

	n = _strcnt(str, drl);

	s = malloc(sizeof(char *) * (n + 1));

	if (!s)
		return (NULL);

	n = 0;
	for (i = 0; str[i] ; i++)
	{
		if (!str_find(drl, str[i]))
			continue;
		if (i == at)
		{
			at = i + 1;
			continue;
		}
		s[n] = malloc(i - at + 1);
		if (!s[n])
		{
			for (j = 0; j < n; j++)
				free(s[j]);
			free(s);
			return (NULL);
		}

		for (j = at; j < i; j++)
			s[n][j - at] = str[j];
		s[n][j - at] = '\0';
		n++;
		at = i + 1;
	}
	s[n] = NULL;
	return (s);
}

/**
 * freeString - free array of strings
 * @str: string to free
 *
 */
void freeString(char **str)
{
	int i = 0;

	if (!str)
		return;

	while (str[i])
	{
		free(str[i]);
		i++;
	}

	free(str);
}
