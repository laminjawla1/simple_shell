#include "main.h"

/**
* main - Entry point to shell program
*
*Return: 0 on success
*/
int main(void)
{
	char *prompt = "$ ", *line = NULL;
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
		printf("%s", line);

		/*Tokenize the command*/
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
