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
	if (!cmd || _strcmp(*argv, "env") == 0)
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
	ssize_t fp;
	char **_argv;
	int n = 1;
	size_t buff_size = BUFF_SIZE;

	fp = open(argv[1], O_RDONLY);
	if (fp == -1)
		return (-1);
	buffer = malloc(sizeof(char) * 1024);
	if (!buffer)
	{
		close(fp);
		return (-1);
	}
	while (read(fp, buffer, buff_size) > 0)
	{
		printf("Read: %s\n", buffer);
		_argv = tokenize(buffer, " \n");
		execute(_argv, *argv, NULL, n);
		free_argv(_argv);
		n++;
	}
	free(buffer);
	close(fp);
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
		if (_strcmp(*argv, "exit") == 0)
			free_argv(commands);
		execute(argv, s_name, user_input, n);
		free_argv(argv);
	}
	free_argv(commands);
}
