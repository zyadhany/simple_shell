#include "s_shell.h"


/**
 * set_envp - add envirnoment variables to the info.
 *
 * Return: 0 at sucess, -1 fail.
 */
int set_envp(void)
{
	int i;

	for (i = 0; environ[i]; i++)
		if (!add_node(&info.envp, environ[i]))
			return (-1);

	return (0);
}


/**
 * _setenv - set an inviroment variable.
 * @var: name of variabe.
 * @value: value of variable.
 *
 * Return: 0 at sucess, 1 fail.
 */
int _setenv(char *var, char *value)
{
	char *env_var = NULL;

	_unsetenv(var);

	_strcpy(&env_var, var);
	if (!env_var)
		return (1);
	_appendStr(&env_var, "=");
	_appendStr(&env_var, value);
	if (!add_node(&info.envp, env_var))
	{
		free(env_var);
		return (1);
	}
	free(env_var);

	return (0);
}

/**
 * _Mysetenv - set an inviroment variable
 *
 * Return: 0 at sucess, 1 fail.
 */
int _Mysetenv(void)
{
	if (_sstrlen(info.command) != 3)
	{
		_puts("usage: setenv (name) (value)\n");
		return (1);
	}

	return (_setenv(info.command[1], info.command[2]));
}

/**
 * _unsetenv - remove an inviroment variable.
 * @var: name of variabe.
 *
 * Return: 0 at sucess, 1 fail.
 */
int _unsetenv(char *var)
{
	int index = _getEnvp(var);

	if (index == -1)
		return (1);

	delete_node_at_index(&info.envp, index);

	return (0);
}

/**
 * _Myunsetenv - remove an inviroment variable.
 *
 * Return: 0 at sucess, 1 fail.
 */
int _Myunsetenv(void)
{
	int i;

	for (i = 1; info.command[i]; i++)
		_unsetenv(info.command[i]);

	return (0);
}
