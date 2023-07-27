#include "main.h"

/**
* _getline - Gets a line of text from the given stream
*
*Return: NULL on error else: A pointer to lineptr
*/
char *_getline(void)
{
	char *lineptr = NULL;
	int r;
	size_t n = 0;

	r = getline(&lineptr, &n, stdin);
	if (r > 0)
		return (lineptr);
	return (NULL);
}
