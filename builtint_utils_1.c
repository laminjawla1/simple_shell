#include "main.h"

/**
* exit_shell - Exits the shell program
*
*@argv: Argument vector
*@user_input: User input
*
*Return: None
*/
int exit_shell(char **argv, char *user_input)
{
	free(user_input);
	free_argv(argv);
	_exit(0);
}
