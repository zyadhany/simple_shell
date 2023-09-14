#include "s_shell.h"

/**
 * _setenv - set an inviroment variable.
 * @var: name of variabe.
 * @value: value of variable.
 *
 * Return: 0 at sucess, 1 fail.
 */
int _setenv(char *var, char *value)
{
	_puts(var);
	_puts(value);

	return (0);
}

/**
 * _Mysetenv - set an inviroment variable
 *
 * Return: 0 at sucess, 1 fail.
 */
int _Mysetenv(void)
{
	

	return (0);
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
