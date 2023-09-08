#include "s_shell.h"

/**
 *_putchar - print char
 *@c: char to be print
 *
 * Return: 1 in success , -1 on fail.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 *_puts - prints an input string
 *@str: the string to be printed
 *
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
