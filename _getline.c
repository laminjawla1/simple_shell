#include "main.h"

/**
* _getline - Gets a line of text from the given stream
*
*@lineptr: A pointer to point to the read string
*@n: A pointer to the size of the string
*@stream: A stream from which to read from
*
*Return: -1 on error else: the number of characters read
*/
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	int ret_val;

	ret_val = getline(lineptr, n, stream);
	return (ret_val);
}
