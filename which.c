#include "main.h"

/**
* _which - Locates the given command
*
*@command: Relative name of the command
*
*Return: NULL or the full path of the specified command
*/
char *_which(char *command)
{
	char *path = NULL, *dir = NULL, *backup_path = NULL, *filepath = NULL;
	size_t cmd_len, len;

	if (!command)
		return (NULL);
	if (access(command, R_OK) == 0)
	{
		len = _strlen(command) + 1;
		filepath = malloc(sizeof(char) * len);
		_strcpy(filepath, command);
		return (filepath);
	}
	path = getenv("PATH");
	backup_path = _strdup(path);
	dir = strtok(backup_path, ":");
	cmd_len = _strlen(command);
	while (dir)
	{
		filepath = malloc(sizeof(char) * (_strlen(dir) + cmd_len + 2));
		_strcpy(filepath, dir);
		filepath = _strcat(filepath, "/");
		filepath = _strcat(filepath, command);
		if (access(filepath, R_OK) == 0)
		{
			free(backup_path);
			return (filepath);
		}
		free(filepath);
		dir = strtok(NULL, ":");
	}
	free(backup_path);
	return (NULL);
}
/**
* reference_builtin - Look for a function defining the builtin command given
*
*@cmd: The given command
*
*Return: On success, a pointer to the function else NULL
*/
int (*reference_builtin(char *cmd))(char **argv, char *user_input)
{
	builtint_t table[] = {
		{"exit", exit_shell},
		{"env", print_env},
		{NULL, NULL}
	};
	int i = 0;

	while (table[i].name)
	{
		if (_strcmp(cmd, table[i].name) == 0)
			return (table[i].f);
		i++;
	}
	return (NULL);
}
