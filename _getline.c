/*
Betty problems I tried to fix to no avail:
More than 40 lines of code
DOS line endings
Trailing white space
*/
#include "s_shell.h"
/**
 * _getline - gets input from user
 * @lineptr: line of input to get
 * @n: byte size of lineptr
 * @fd: file descriptor
 * Return: total bytes of input read
*/
ssize_t _getline(char **lineptr, size_t *n, int fd)
{
	if (lineptr == NULL || n == NULL || fd < 0)
		return (-1);

	ssize_t bytesRead = 0, totalBytesRead = 0;
	char *buffer = malloc(BUFFER_SIZE);

	if (buffer == NULL)
		return (-1);

	while (1)
	{
		bytesRead = read(fd, buffer + totalBytesRead, 1);
		if (bytesRead == -1)
		{
			perror("read");
			free(buffer);
			return (-1);
		}
		else if (bytesRead == 0)
			break; /*EOF*/

		totalBytesRead += bytesRead;

		/*Check for end of line*/
		if (buffer[totalBytesRead - 1] == '\n')
			break;

		/*If buffer is full, reallocate*/
		if (totalBytesRead >= BUFFER_SIZE)
		{
			char *newBuffer = realloc(buffer, 2 * BUFFER_SIZE);

			if (newBuffer == NULL)
			{
				free(buffer);
				return (-1);
			}
			buffer = newBuffer;
		}
	}
	/*Null-terminate the string*/
	buffer[totalBytesRead] = '\0';

	/*Update the lineptr and n parameters*/
	if (*lineptr == NULL || *n < totalBytesRead + 1)
	{
		*lineptr = realloc(*lineptr, totalBytesRead + 1);
		if (*lineptr == NULL)
		{
			free(buffer);
			return (-1);
		}
		*n = totalBytesRead + 1;
	}
	_strcpy(*lineptr, buffer);

	free(buffer);
	return (totalBytesRead);
}
