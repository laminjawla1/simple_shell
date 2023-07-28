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
	int e_status_code = 0;
	char *exit_code = argv[1];

	if (!exit_code)
	{
		free(user_input);
		free_argv(argv);
		_exit(e_status_code);
	}
	else
		if (_isdigit(exit_code))
		{
			e_status_code = atoi(exit_code);
			free(user_input);
			free_argv(argv);
			_exit(e_status_code);
		}
	return (-1);
}
/**
* print_env - Prints the environment variable
*
*@av: Argument vector
*@ui: The user input
*
*Return: 0 on success
*/
int print_env(char **av, char *ui)
{
	char __attribute__((unused)) *argv = NULL;
	int i;

	if (!environ)
		return (-2);
	argv = *av;
	argv = ui;
	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}
