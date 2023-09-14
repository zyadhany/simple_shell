#include "s_shell.h"


/**
 * set_envp - add envirnoment variables to the info.
 *
 */
void set_envp(void)
{
	int i;

	for (i = 0; environ[i]; i++)
		info.envp = add_node(&info.envp, environ[i]);
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

	/* add node */

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
	_puts(var);

	return (0);
}

/**
 * _Myunsetenv - remove an inviroment variable.
 *
 * Return: 0 at sucess, 1 fail.
 */
int _Myunsetenv(void)
{
	_puts("HI\n");

	return (0);
}
