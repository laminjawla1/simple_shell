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
	char *filepath = NULL, *path = NULL, *dir = NULL, *backup_path;
	size_t len;
	struct stat buf;

	if (!command)
		return (NULL);
	path = getenv("PATH");
	if (!path)
		return (NULL);
	backup_path = strdup(path);
	dir = strtok(backup_path, ":");
	while (dir)
	{
		len = strlen(dir) + strlen(command) + 2;
		filepath = malloc(sizeof(char) * len);
		if (!filepath)
		{
			free(backup_path);
			return (NULL);
		}
		snprintf(filepath, len, "%s/%s", dir, command);
		if ((stat(filepath, &buf)) == 0)
		{
			free(backup_path);
			return (filepath);
		}
		dir = strtok(NULL, ":");
		free(filepath);
	}
	free(backup_path);
	return (command);
}
