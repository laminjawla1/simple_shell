#include "main.h"

/**
* _strchr - Checks if a character is in a string
*
*@s: Base string
*@c: Character to be looked for
*
*Return: true or false
*/
bool _strchr(char *s, char c)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] == c)
			return (true);
		i++;
	}
	return (false);
}

/**
* _strlen - Finds the length of a string
*
*@s: The string to be checked
*
*Return: len(s)
*/
size_t _strlen(char *s)
{
	size_t len = 0;
	int i = 0;

	while (s[i])
	{
		len++;
		i++;
	}
	return (len);
}
/**
* _strdup - Duplicates a string
*
*@s: The string to be duplicated
*
*Return: A duplicate of the string provided
*/
char *_strdup(char *s)
{
	char *new_str;
	size_t len;

	len = _strlen(s);
	new_str = malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	_strcpy(new_str, s);
	return (new_str);
}
/**
* _strcpy - Copies src to dest
*
*@dest: Destination
*@src: Source
*
*Return: Void
*/
void _strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i]; i++)
		dest[i] = src[i];
	dest[i] = '\0';
}
