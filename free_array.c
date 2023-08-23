#include "simple_shell.h"
/**
 * free_array - function to free a array
 * @tokens: array to be free
 * Return: Theres no return. (void)
 */
void free_array(char **tokens)
{
	int i = 0;

	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}

	free(tokens);
}
