#include "shell.h"
/**
* getLocation - a function to get location
* @cmd: command to be pressed
* Return: location
*/

char *getLocation(char *cmd)
{
	char *path, *pathcopy, *pathtoken, *filepath;
	int cmd_length, directory_length;
	struct stat buff;

	path = getenv("PATH");

	if (path)
	{
		pathcopy = strdup(path);
		cmd_length = strlen(cmd);
		pathtoken = strtok(pathcopy, ":");
		while (pathtoken != NULL)
		{
			directory_length = strlen(pathtoken);
			filepath = malloc(cmd_length + directory_length + 2);
			strcpy(filepath, pathtoken);
			strcat(filepath, "/");
			strcat(filepath, cmd);
			strcat(filepath, "\0");
			if (stat(filepath, &buff) == 0)
			{
				free(pathcopy);
				return (filepath);
			}
			else
			{
				free(filepath);
				pathtoken = strtok(NULL, ":");
			}
		}
		free(pathcopy);
		if (stat(cmd, &buff) == 0)
		{
			return (cmd);
		}
		return (NULL);
	}
	return (NULL);
}
