#include "main.h"

/**
*execute - Executes a command passed to it
*
*@argv: A command to be executed
*@p_name: The name of the shell
*/
void execute(char **argv, char *p_name)
{
	pid_t pid;

	if (!*argv)
		return;
	pid = fork();
	if (pid == -1)
		return;
	else if (pid == 0)
	{
		if ((execve(argv[0], argv, NULL)) == -1)
			perror(p_name);
	}
	else
		wait(NULL);
}

