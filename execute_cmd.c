#include "main.h"

/**
*execute - Executes a command passed to it
*
*@argv: A command to be executed
*@p_name: The name of the shell
*@number_of_commands_executed: Number of commands executed
*/
void execute(char **argv, char *p_name, int number_of_commands_executed)
{
	char *cmd, error_msg[1024];
	pid_t pid;

	if (!*argv)
		return;
	pid = fork();
	if (pid == -1)
		return;
	else if (pid == 0)
	{
		cmd = _which(argv[0]);
		if (!cmd)
			return;
		if ((execve(cmd, argv, NULL)) == -1)
		{
			snprintf(error_msg, 1024, "%s: %d: %s: not found\n",
			p_name, number_of_commands_executed, *argv);
			write(STDERR_FILENO, error_msg, strlen(error_msg));
		}
	}
	else
		wait(NULL);
}

