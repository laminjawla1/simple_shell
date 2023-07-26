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
