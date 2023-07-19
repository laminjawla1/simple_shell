#include "main.h"

/**
*execute - Executes a command passed to it
*
*@argv: A command to be executed
*@s_name: The name of the shell program
*@user_input: User input
*@count: Number of commands executed
*/
void execute(char **argv, char *s_name, char *user_input, size_t count)
{
	char *cmd = NULL;
	pid_t pid;
	int (*f)(char **, char *);
	int ec;

	if (!*argv)
		return;
	cmd = _which(*argv);
	if (!cmd || strcmp(*argv, "env") == 0)
	{
		f = reference_builtin(*argv);
		if (f)
		{
			ec = f(argv, user_input);
			if (ec == -1)
				print_error_msg(s_name, *argv, argv[1], count);
			free(cmd);
			return;
		}
		else
			print_error_msg(s_name, *argv, NULL, count);
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
/**
* execute_from_file - Opens a file and runs the commands in it
*
*@argv: Argument vector
*
*Return: 0 on success
*/
int execute_from_file(char **argv)
{
	char *buffer;
	FILE *fp;
	char **_argv;
	int n = 1;

	fp = fopen(argv[1], "r");
	if (!fp)
		return (-1);
	buffer = malloc(sizeof(char) * 1024);
	if (!buffer)
		return (-1);
	while (fgets(buffer, sizeof(buffer), fp))
	{
		_argv = tokenize(buffer, " \n");
		execute(_argv, *argv, NULL, n);
		free_argv(_argv);
		n++;
	}
	free(buffer);
	fclose(fp);
	return (0);

}
