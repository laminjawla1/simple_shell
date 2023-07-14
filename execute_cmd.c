#include "main.h"

/**
*execute - Executes a command passed to it
*
*@argv: A command to be executed
*@p_name: The name of the shell
*/
void execute(char **argv, char *p_name)
{
	char *cmd;
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
			perror(p_name);
	}
	else
		wait(NULL);
}

