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
	int i = 0;
	char *token = NULL;
	char **array = NULL;


	/* Allocate space for the array of tokens */
	array = malloc(strlen(ptr) + 1);

	/* Tokenize the input string using strtok */
	token = strtok(ptr, delim);

	while (token)
	{
		/* Allocate space for the token and copy it */
		array[i] = malloc(sizeof(char) * (strlen(token) + 1));
		strcpy(array[i], token);

		i++;
		token = NULL; /*Reset token */

		/* Tokenize the next part of the input string */
		token = strtok(NULL, delim);
	}

	array[i] = NULL; /*Mark the end of the array with NULL*/
	free(token);      /*Free the last token (if any)*/
	return (array);
}
