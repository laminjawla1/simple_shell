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
	size_t n = 0;
	int val_from_getline, number_of_commands_executed = 1;

	/*signal(SIGINT, signal_handler);*/
	while (true)
	{
		/*Display an input prompt to the user fd is pointing to the terminal*/
		if (isatty(STDIN_FILENO))
			display_prompt(prompt);

		/*Get a text line from the user*/
		val_from_getline = getline(&user_input, &n, stdin);
		if (val_from_getline != -1)
		{
			/*Tokenize the command*/
			_argv = tokenize(user_input, sep);
			/*Check if the user wants to exit*/
			if (*_argv && strcmp(_argv[0], "exit") == 0)
			{
				free(user_input);
				free_argv(_argv);
				_exit(0);
			}
			/*Execute the command*/
			execute(_argv, argv[0], number_of_commands_executed);
			/*Clean up the memory*/
			free_argv(_argv);
		}
		else
		{
			putchar('\n');
			free(user_input);
			_exit(0);
		}
		number_of_commands_executed++;
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
