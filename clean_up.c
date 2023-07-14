#include "main.h"

/**
* free_argv - Frees the memory allocated to argv
*
*@argv: Argument vector
*
*Return: None
*/
void free_argv(char **argv)
{
	int i;

	for (i = 0; argv[i]; i++)
		free(argv[i]);
	free(argv);
}
