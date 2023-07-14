#include "main.h"

/**
* main - Entry point to shell program
*
*Return: 0 on success
*/
int main(int __attribute__((unused)) argc, char **argv)
{
	char *prompt = "$ ", *sep = " \n", *line = NULL, **_argv = NULL;
	size_t n = 0;
	int val_from_getline;

	while (true)
	{
		/*Display an input prompt to the user*/
		display_prompt(prompt);

		/*Get a text line from the user*/
		val_from_getline = getline(&line, &n, stdin);
		if (val_from_getline == -1)
		{
			putchar('\n');
			free(line);
			exit(0);
		}
		/*Tokenize the command*/
		_argv = tokenize(line, sep);
		/*Check if the user wants to exit*/
		if (_argv[0] && strcmp(_argv[0], "exit") == 0)
		{
			free(line);
			free_argv(_argv);
			exit(0);
		}
		/*Execute the command*/
		execute(_argv, argv[0]);
		/*Clean up the memory*/
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
	printf("%s", prompt);
}
