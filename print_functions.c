#include "s_shell.h"

/**
 * _putchar - prints character to stdout
 * @c: char to be print
 * Return: 1 on success , -1 on failure
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - prints an input string
 * @str: the string to be printed
 * Return: Nothing
 */
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;

	while (str[i] != '\0')
		_putchar(str[i++]);

}

/**
 * print_int - prints an integer
 * @n: integer to print
 */
void print_int(int n)
{
	int i;
	char s[32];

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

	_puts(s);
}
