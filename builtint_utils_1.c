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
/**
* print_env - Prints the environment variable
*
*@av: Argument vector
*@ui: The user input
*
*Return: 0 on success
*/
int print_env(char **av, char __attribute__((unused)) *ui)
{
	char __attribute__((unused)) *argv = NULL;
	int i;

	argv = *av;
	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}
