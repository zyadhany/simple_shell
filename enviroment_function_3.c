#include "s_shell.h"

/**
 * get_env_val - get value of variable start wiht $.
 * @var: given var
 * Return: array of strings
 */
char *get_env_val(char *var)
{
	int n = _strlen(var);

	if (n < 2)
		return (var);

	if (var[0] != '$')
		return (var);

	if (var[1] == '$')
		return (int_to_string(getpid()));

	if (var[1] == '?')
		return (int_to_string(info.status));

	return (env_val(var + 1));
}

/**
 * _strcnt_env - counts number of strings after break
 * @str: string to break
 * Return: array of strings
 */
int _strcnt_env(char *str)
{
	int n = 0, i, at = 0, len = _strlen(str);

	if (!str)
		return (0);

	for (i = 0; i <= len; i++)
	{
		if ((str[i] == '$' || str[i] == '?') && i == at + 1)
			i++;
		else if ((str[i] != '$' && str[i]) || i == at)
			continue;
		n++;
		at = i;
	}

	return (n);
}

/**
 * _strtok_env - breaks string into several strings
 * @str: string to be break
 * Return: array of strings
 */
char **_strtok_env(char *str)
{
	int n = 0, len = _strlen(str), i, j, at = 0;
	char **s;

	s = malloc(sizeof(char *) * (_strcnt_env(str) + 1));

	if (!s)
		return (NULL);

	for (i = 0; i <= len; i++)
	{
		if ((str[i] == '$' || str[i] == '?') && i == at + 1)
			i++;
		else if ((str[i] != '$' && str[i]) || i == at)
			continue;

		s[n] = malloc(sizeof(char) * (i - at + 1));
		if (!s[n])
		{
			freeString(s);
			return (NULL);
		}

		for (j = at; j < i; j++)
			s[n][j - at] = str[j];

		s[n][j - at] = '\0';
		n++;
		at = i;
	}

	s[n] = NULL;
	return (s);
}

/**
 * separate_to_enviroment - sprate string into sevral enviroment variable.
 * @args: 2d array to sprate at.
 * @str: string to sprate from.
 *
 * Return: 0 at sucess -1 at filed.
 */
int separate_to_enviroment(char ***args, char *str)
{
	int i;

	if (!args)
		return (-1);

	*args = _strtok_env(str);

	if (!(*args))
		return (-1);

	for (i = 0; (*args)[i]; i++)
		if ((*args)[i][0] == '$')
			if (_strcpy(&((*args)[i]), get_env_val((*args)[i])) == -1)
			{
				freeString(*args);
				return (-1);
			}

	return (0);
}

/**
 * replace_to_env - replace string with it's enviroment variable.
 * @str: string to be replaced.
 *
 * Return: 0 at sucess -1 at filed.
 */
int replace_to_env(char **str)
{
	char **args = NULL;

	if (!str)
		return (-1);

	if (separate_to_enviroment(&args, *str) == -1)
		return (-1);

	if (_strassemb(args, str) == -1)
	{
		freeString(args);
		return (-1);
	}

	freeString(args);
	return (0);
}
