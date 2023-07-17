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
	char *path, *dir, *backup_path;
	size_t cmd_len, len;
	struct stat buf;
	char *filepath;

	if (!command)
		return (NULL);
	if (stat(command, &buf) == 0)
	{
		len = strlen(command) + 1;
		filepath = malloc(sizeof(char) * len);
		snprintf(filepath, len, "%s", command);
		return (filepath);
	}
	path = getenv("PATH");
	backup_path = strdup(path);
	dir = strtok(backup_path, ":");
	cmd_len = strlen(command);
	while (dir)
	{
		len = strlen(dir) + cmd_len + 2;
		filepath = malloc(sizeof(char) * len);
		snprintf(filepath, len, "%s/%s", dir, command);
		if (stat(filepath, &buf) == 0)
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
