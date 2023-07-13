#include "main.h"

/**
*execute - Executes a command passed to it
*
*@argv: A command to be executed
*@p_name: The name of the shell
*/
void execute(char **argv, char *p_name)
{
	if (!*argv)
		return;
	if ((execve(argv[0], argv, NULL)) == -1)
		perror(p_name);
}

