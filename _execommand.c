#include "shell.h"
/**
 * execommand - a function to execute command
 * @argument_v: argument to be executed
 * Return: void
 */

void execommand(char **argument_v)
{
	char *cmd = NULL, *actual_cmd = NULL;
	pid_t processID;
	int stats;

	processID = fork();

	if (processID == 0)
	{
		if (argument_v)
		{
			cmd = argument_v[0];
			actual_cmd = getLocation(cmd);
			if (execve(actual_cmd, argument_v, NULL) == -1)
			{
				perror("Error: ");
			};
			exit(-1);
		}
	}
	else if (processID < 0)
	{
		perror("Error: ");
	}
	else
	{
		wait(&stats);
	}
}
