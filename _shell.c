#include "shell.h"

/**
 * main - a function to create  a shell
 * @argument_c: arg c
 * @argument_v: arg v
 * Return: 0 if success
 */

int main(int argument_c, char **argument_v)
{
	char *prompt_s = "$ ";
	char *linepointer;
	size_t num = 0;
	ssize_t numchars_read;
	char *linepointer_c = NULL;
	const char *delimeter = " \n";
	int number_token = 0;
	char *token;
	int j;

	(void)argument_c;

	while (1)
	{
		printf("%s", prompt_s);
		numchars_read = getline(&linepointer, &num, stdin);
		if (numchars_read == -1)
		{
			printf("Exit...\n");
			return (-1);
		}

		linepointer_c = malloc(sizeof(char) * numchars_read);
		if (linepointer_c == NULL)
		{
			perror("Failed to allocate memory...");
			return (-1);
		}

		strcpy(linepointer_c, linepointer);
		token = strtok(linepointer, delimeter);

		while (token != NULL)
		{
			number_token++;
			token = strtok(NULL, delimeter);
		}
		number_token++;

		argument_v = malloc(sizeof(char *) * number_token);
		token = strtok(linepointer_c, delimeter);
		for (j = 0; token != NULL; j++)
		{
			argument_v[j] = malloc(sizeof(char) * strlen(token));
			strcpy(argument_v[j], token);

			token = strtok(NULL, delimeter);
		}
		argument_v[j] = NULL;
		execommand(argument_v);
	}
	free(linepointer_c);
	free(linepointer);
	return (0);
}
