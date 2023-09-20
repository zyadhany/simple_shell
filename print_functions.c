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
	_puts(int_to_string(n));
}


/**
 * _getline - gets input from user
 * @lineptr: line of input to get
 * @len: byte size of lineptr
 * @fd: file descriptor
 * Return: total bytes of input read
*/
int _getline(char **lineptr, int *len, int fd)
{
	int n = 0, bytesRead = 0;
	char c;

	if (!lineptr || !len || fd < 0)
		return (-1);

	Buff_Flush();
	free(*lineptr);
	*lineptr = NULL;

	do {
		bytesRead = read(fd, info.buffer + info.buffer_index, 1);
		c = info.buffer[info.buffer_index];

		if (!bytesRead)
			break;
		if (bytesRead == -1)
			return (-1);

		info.buffer_index++;
		n++;

		if (c == '\n' || c == -1)
			break;

		if (info.buffer_index == BUFFER_SIZE)
		{
			_appendStr(lineptr, info.buffer);
			Buff_Flush();
		}
	} while (bytesRead);

	info.buffer[info.buffer_index] = '\0';
	_appendStr(lineptr, info.buffer);

	if (n == 0)
		return (-1);

	return (n);
}
