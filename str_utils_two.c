#include "main.h"

/**
* _strcmp - Compares s1 and s2
*
*@s1: First string
*@s2: Second string
*
*Return: 0 if s1 == s2, 1 if s1 > s2, -1 if s2 > s1
*/
int _strcmp(char *s1, char *s2)
{
	while (*s1)
	{
		if (*s1 != *s2)
			break;
		s1++;
		s2++;
	}
	return (*(const unsigned char *) s1 - *(const unsigned char *) s2);
}
/**
* strip - Removes preceding spaces from user input
*
*@str: String to be sterilize
*
*Return: Sterilize string
*/
char *strip(char *str)
{
	int i = 0, j = 0;
	char *buff = malloc(sizeof(char) * (_strlen(str) + 1));

	if (!buff)
	{
		free(buff);
		return (NULL);
	}
	for (i = 0; str[i] == ' '; i++)
		;
	while (str[i + 1] != '\0')
	{
		buff[j] = str[i];
		j++;
		i++;
	}
	buff[j] = '\0';
	if (buff[0] == '\0' || buff[0] == '#')
	{
		free(buff);
		return (NULL);
	}
	return (buff);
}
