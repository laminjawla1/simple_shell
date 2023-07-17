#include "main.h"

/**
*execute - Executes a command passed to it
*
*@argv: A command to be executed
*@p_name: The name of the shell program
*@user_input: User input
*@count: Number of commands executed
*/
void execute(char **argv, char *p_name, char *user_input, size_t count)
{
	char *cmd = NULL, error_msg[1024];
	pid_t pid;
	int (*f)(char **, char *);

	if (!*argv)
		return;
	cmd = _which(*argv);
	if (!cmd)
	{
		f = reference_builtin(*argv);
		printf("*argv: %s\n", *argv);
		if (f)
		{
			f(argv, user_input);
			return;
		}
		else
		{
			snprintf(error_msg, 1024, "%s: %ld: %s: not found\n",
				p_name, count, *argv);
			print_error_msg(STDERR_FILENO, error_msg);
			return;
		}
	}
	pid = fork();
	if (pid == -1)
		return;
	else if (pid == 0)
		execve(cmd, argv, NULL);
	else
	{
		wait(NULL);
		free(cmd);
	}
}
