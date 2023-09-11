#include "s_shell.h"

/**
 * _strlen - gets length of a string
 * @str: string whose length is needed
 * Return: length of given string.
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
 * str_find - finds character(s) in a string
 * @str: string to check
 * @c: character to find in string
 * Return: 1 if found, 0 otherwise.
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
 * _strcnt - counts number of strings after break
 * @str: string to break
 * @dlm: what to break at (Delimeter)
 * Return: array of strings
 */
int _strcnt(char *str, char *dlm)
{
	int n = 0, i, at = 0;

	if (!str)
		return (0);

	for (i = 0; str[i] ; i++)
	{
		if (!str_find(dlm, str[i]))
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
 * _strtok - breaks string into several strings
 * @str: string to be break
 * @dlm: what to break at (Delimiter)
 * Return: array of strings
 */
char **_strtok(char *str, char *dlm)
{
	int n = 0, i, j, at = 0;
	char **s;

	n = _strcnt(str, dlm);
	s = malloc(sizeof(char *) * (n + 1));

	if (!s)
		return (NULL);

	n = 0;
	for (i = 0; str[i] ; i++)
	{
		if (!str_find(dlm, str[i]))
			continue;
		if (i == at)
		{
			at = i + 1;
			continue;
		}

		s[n] = malloc(sizeof(char) * (i - at + 1));

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
 * freeString - frees an array of strings
 * @str: string to free
 *
 */
void freeString(char **str)
{
	int i = 0;

	if (!str)
		return;

	while (str[i])
		free(str[i++]);

	free(str);
}
