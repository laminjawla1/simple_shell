#include "main.h"

/**
*execute - Executes a command passed to it
*
*@argv: A command to be executed
*@cmd: The full path to command to be executed
*/
void execute(char **argv, char *cmd)
{
	pid_t pid;

	if (!*argv)
		return;
	pid = fork();
	if (pid == -1)
		return;
	else if (pid == 0)
	{
		execve(cmd, argv, NULL);
		free(cmd);
	}
	else
		wait(NULL);
}
