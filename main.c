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
	char *prompt = "$ ", *sep = " \n", *user_input = NULL, **_argv;
	size_t number_of_commands_executed = 1;

	signal(SIGINT, signal_handler);
	if (argc == 1)
	{
		while (true)
		{
			if (isatty(STDIN_FILENO))
				display_prompt(prompt);
			user_input = _getline(STDIN_FILENO);
			if (user_input)
			{
				user_input = handle_comments(user_input);
				if (!_strchr(user_input, ';'))
				{
					_argv = tokenize(user_input, sep);
					execute(_argv, *argv, user_input, number_of_commands_executed);
					free_argv(_argv);
				}
				else
					execute_semicolon_sep(user_input, *argv, number_of_commands_executed);
				free(user_input);
			}
			else
			{
				if (isatty(STDIN_FILENO))
					write(STDIN_FILENO, "\n", 1);
				_exit(0);
			}
			number_of_commands_executed++;
		}
	}
	else
	{
		printf("Here\n");
		execute_from_file(argv);
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
