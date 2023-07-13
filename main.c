#include "main.h"

/**
* main - Entry point to shell program
*
*Return: 0 on success
*/
int main(void)
{
	char *prompt = "$ ", *sep = " \n", *line = NULL, **_argv = NULL;
	size_t n = 0, i;
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
		printf("Tokens:\n");
		for (i = 0; _argv[i]; i++)
			printf("_argv[%lu]: %s\n", i, _argv[i]);
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
