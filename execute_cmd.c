#include "main.h"

/**
*execute - Executes a command passed to it
*
*@argv: A command to be executed
*@p_name: The name of the shell program
*@n_cmds_executed: Number of commands executed
*/
void execute(char **argv, char *p_name, size_t n_cmds_executed)
{
	char *cmd = NULL, error_msg[1024];
	pid_t pid;

	if (!*argv)
		return;
	cmd = _which(*argv);
	if (!cmd)
	{
		snprintf(error_msg, 1024, "%s: %ld: %s: not found\n",
			p_name, n_cmds_executed, *argv);
		print_error_msg(STDERR_FILENO, error_msg);
		return;
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
