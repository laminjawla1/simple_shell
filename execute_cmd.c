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
		execve(cmd, argv, environ);
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
/**
* execute_semicolon_sep - Execute commands separated by semicolons
*
*@user_input: The commands entered by the user
*@s_name: The name of the shell program
*@n: Number of commands executed
*
*Return: Void
*/
void execute_semicolon_sep(char *user_input, char *s_name, int n)
{
	char **commands, **argv = NULL;
	int i;

	commands = tokenize(user_input, ";\n");
	for (i = 0; commands[i]; i++)
	{
		argv = tokenize(commands[i], " \n");
		execute(argv, s_name, NULL, n);
		free_argv(argv);
	}
	free_argv(commands);
}
