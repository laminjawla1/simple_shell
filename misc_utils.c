#include "main.h"

/**
* _isdigit - Checks if a number is a digit or not
*
*@s: The string to checked
*
*Return: True or False
*/
bool _isdigit(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
		if (!isdigit(s[i]))
			return (false);
	return (true);
}
/**
* handle_comments - Substitute a '#' to '\0'
*
*@command: A command to be checked
*
*Return: The modified string
*/
char *handle_comments(char *command)
{
	int i;

	for (i = 0; command[i]; i++)
	{
		if (command[i] == '#' && (!i || command[i - 1] == ' '))
		{
			command[i] = '\0';
			break;
		}
	}
	return (command);
}
