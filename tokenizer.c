#include "main.h"

/**
* tokenize - Split the given string into tokens
*
*@line: A line of string
*@sep: Separator or delimiter
*
*Return: An array of strings
*/
char **tokenize(char *line, char *sep)
{
	char **argv, *token = NULL, *backup;
	size_t number_of_tokens, i = 0;

	backup = strdup(line);
	number_of_tokens = get_number_of_tokens(backup, sep);
	argv = malloc(sizeof(char *) * (number_of_tokens + 1));
	if (!argv)
	{
		perror("hsh: Memory allocation failed");
		exit(-1);
	}
	free(backup);
	backup = strdup(line);
	token = strtok(backup, sep);
	while (token)
	{
		argv[i] = malloc(sizeof(char) * (strlen(token) + 1));
		if (!argv[i])
		{
			free(argv);
			perror("hsh: Memory allocation failed");
			exit(-1);
		}
		strcpy(argv[i], token);
		token = strtok(NULL, sep);
		i++;
	}
	free(backup);
	argv[i] = NULL;
	return (argv);
}
/**
* get_number_of_tokens - Get the number of tokens in a given line
*
*@line: String of text
*@sep: Separator
*
*Return: Number of tokens
*/
size_t get_number_of_tokens(char *line, char *sep)
{
	char *token;
	size_t number_of_tokens = 0;

	token = strtok(line, sep);
	while (token)
	{
		number_of_tokens++;
		token = strtok(NULL, sep);
	}
	return (number_of_tokens);
}
