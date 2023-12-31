#include "simple_shell.h"

/**
 * tokenization - Extracts tokens from the input string.
 *
 * @ptr: Input string to tokenize.
 * @delim: Delimiter string.
 *
 * Return: Returns an array of tokens.
 *
 * Description: This function takes an input string and a delimiter and
 * tokenizes the input string based on the delimiter. It returns an array
 * of pointers to each token.
 */
char **tokenization(char *ptr, char *delim)
{
		char *token = NULL, **tokens = NULL;
	int i = 0;

	tokens = malloc(sizeof(char *) * 64);
	if (!tokens)
	{
		fprintf(stderr, "lsh: allocation error\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(ptr, delim);

	while (token)
	{
		tokens[i] = malloc(sizeof(char) * (strlen(token) + 1));

		strcpy(tokens[i], token);
		i++;
		token = NULL;
		token = strtok(NULL, delim);
	}
		char **tokens = NULL;
	char *token = NULL;
	int i = 0;

	tokens = malloc(sizeof(char *) * 10);
	token = strtok(ptr, delim);

	while (token)
	{
		tokens[i] = malloc(sizeof(char) * (strlen(token) + 1));
		strcpy(tokens[i], token);
		i++;
		token = strtok(NULL, delim);
	}

		tokens[i] = NULL;

		free(token);
	return (tokens);
		return (tokens);
}
