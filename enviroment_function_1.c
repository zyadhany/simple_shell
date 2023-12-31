#include "s_shell.h"

/**
 * set_envp - add envirnoment variables to info structure
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
 * _setenv - sets an inviroment variable
 * @var: name of variabe
 * @value: value of variable
 * Return: 0 on sucess, 1 on failure
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

	info.enviroment_changed = 1;
	free(env_var);

	return (0);
}

/**
 * _Mysetenv - sets an enviroment variable
 * Return: 0 on sucess, 1 on failure
 */
int _Mysetenv(void)
{
	if (_sstrlen(info.command) != 3)
	{
		_puts("usage: setenv (name) (value).\n");
		return (1);
	}

	return (_setenv(info.command[1], info.command[2]));
}

/**
 * _unsetenv - unsets an enviroment variable
 * @var: name of variabe
 * Return: 0 on sucess, 1 on failure
 */
int _unsetenv(char *var)
{
	int index = _getEnvp(var);

	if (index == -1)
		return (1);

	delete_node_at_index(&info.envp, index);
	info.enviroment_changed = 1;

	return (0);
}

/**
 * _Myunsetenv - removes an enviroment variable
 * Return: 0 on sucess, 1 on failure
 */
int _Myunsetenv(void)
{
	int i;

	if (_sstrlen(info.command) == 1)
	{
		_puts("Too few arguements.\n");
		return (1);
	}

	for (i = 1; info.command[i]; i++)
		if (_unsetenv(info.command[i]))
			_puts("variable not found\n");

	return (0);
}
