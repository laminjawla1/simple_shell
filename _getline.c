#include "main.h"

/**
* _getline - Gets a line of text from the given stream
*
*@fd: A stream from which to read from
*
*Return: NULL on error else: A pointer to lineptr
*/
char *_getline(int fd)
{
	char *lineptr = NULL;
	int i = 0, c = 0, r = 0;
	size_t size = BUFF_SIZE;

	lineptr = malloc(sizeof(char) * size);
	while (c != EOF && c != '\n')
	{
		fflush(stdin);
		r = read(fd, &c, 1);
		if (!r)
		{
			free(lineptr);
			return (NULL);
		}
		lineptr[i] = c;
		if (i >= BUFF_SIZE)
		{
			size++;
			lineptr = realloc(lineptr, size);
		}
		i++;
	}
	lineptr[i] = '\0';
	return (lineptr);
}
