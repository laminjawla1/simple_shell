#include "main.h"

/**
* main - Entry point to shell program
*
*@argc: Argument count
*@argv: Argument vector
*
*Return: 0 on success
*/
int main(int __attribute__((unused)) argc, char **argv)
{
	char *prompt = "$ ", *sep = " \n", *user_input = NULL, error_msg[1024];
	char *cmd = NULL, **_argv;
	size_t n = 0, number_of_commands_executed = 1;
	int val_from_getline = 0;

	signal(SIGINT, signal_handler);
	while (true)
	{
		if (isatty(STDIN_FILENO))
			display_prompt(prompt);
		val_from_getline = getline(&user_input, &n, stdin);
		if (val_from_getline != -1)
		{
			_argv = tokenize(user_input, sep);
			if ((*_argv != NULL) && (strcmp(*_argv, "exit") == 0))
			{
				free(user_input);
				free_argv(_argv);
				_exit(0);
			}
			cmd = _which(_argv[0]);
			if (!cmd)
			{
				snprintf(error_msg, 1024, "%s: %ld: %s: not found\n",
					*argv, number_of_commands_executed, *_argv);
				print_error_msg(STDERR_FILENO, error_msg);
			}
			else
			{
				execute(_argv, cmd);
				free(cmd);
			}
		}
		else
		{
			free(user_input);
			putchar('\n');
			_exit(0);
		}
		number_of_commands_executed++;
		free_argv(_argv);
	}
	return (0);
}
/**
* display_prompt - Displays a prompt to the user
*
*@prompt: A prompt message to be displayed
*
*Return: void
*/
void display_prompt(char *prompt)
{
	write(STDOUT_FILENO, prompt, strlen(prompt));
}
