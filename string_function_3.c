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
 * _strSuffix - get suffix from string from given index.
 * @str: given string.
 * @index: given index.
 *
 * Return: string, Null if field.
 */
char *_strSuffix(char *str, int index)
{
	int n, i;
	char *s = NULL;

	n = _strlen(str);

	if (index > n)
		return (NULL);

	s = malloc(sizeof(char) * (n - index + 1));

	for (i = index; str[i]; i++)
		s[i - index] = str[i];

	s[n - index] = '\0';

	return (s);
}

/**
 * _strassemb - collect 2d string into string.
 * @str: given string.
 * @s: output string.
 *
* Return: 0 at sucess -1 at filed.
 */
int _strassemb(char **str, char **s)
{
	int n = 0, i, j, at = 0;

	free(*s);
	*s = NULL;

	if (!str)
		return (-1);

	for (i = 0; str[i]; i++)
		n += _strlen(str[i]);

	*s = malloc(sizeof(char) * (n + 1));

	if (!(*s))
		return (-1);

	for (i = 0; str[i]; i++)
		for (j = 0; str[i][j]; j++)
			(*s)[at++] = str[i][j];

	(*s)[at] = '\0';
	return (0);
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
