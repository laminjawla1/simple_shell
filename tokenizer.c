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
	char **argv, *token, *backup;
	size_t number_of_tokens, i = 0, token_len;

	backup = _strdup(line);
	number_of_tokens = get_number_of_tokens(backup, sep);
	free(backup);
	argv = (char **)malloc(sizeof(char *) * (number_of_tokens + 1));
	backup = _strdup(line);
	token = strtok(backup, sep);
	while (token)
	{
		token_len = _strlen(token);
		argv[i] = (char *)malloc(sizeof(char) * (token_len + 1));
		_strcpy(argv[i], token);
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
