#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */

int main(void)
{
	size_t n = 0;
	char *input = NULL;
	char *input_cpy = NULL;
	char *delim = "\n";
	char *token = NULL;
	int argc = 0, i = 0;
	char **argv = NULL;

	printf("$ ");
	if (getline(&input, &n, stdin) == -1)
	{
		return (-1);
	}

	input_cpy = strdup(input);

	token = strtok(input, delim);

	while (token)
	{
		token = strtok(NULL, delim);
		argc++;
	}

	argv = malloc(sizeof(char *) * argc);
	token = strtok(input_cpy, delim);

	while (token)
	{
		argv[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	argv[i] = NULL;
	i = 0;

	free(input);
	free(input_cpy);
	free(argv);
	return (0);
}
