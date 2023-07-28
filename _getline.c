#include "main.h"

/**
* _getline - Gets a line of text from the given stream
*
*Return: NULL on error else: A pointer to lineptr
*/
char *_getline()
{
	int i, r, buff_size = BUFF_SIZE, c = 0;
	char *buffer, *buf;

	buffer = malloc(sizeof(char) * buff_size);
	if (!buffer)
		return (NULL);
	for (i = 0; c != EOF && c != '\n'; i++)
	{
		fflush(stdin);
		r = read(STDIN_FILENO, &c, 1);
		if (r == 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[i] = c;
		if (i >= buff_size)
		{
			buff_size *= 2;
			buffer = realloc(buffer, buff_size);
			if (!buffer)
			{
				free(buffer);
				return (NULL);
			}
		}
	}
	buffer[i] = '\n';
	buffer[i + 1] = '\0';
	buf = strip(buffer);
	free(buffer);
	return (buf);
}
