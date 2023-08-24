#include "simple_shell.h"

/**
 * die - function that will check if tokens 0 is the word exit
 *
 * @tokens: array of tokens that we will checked only the first token
 *
 * Return: 1, if the word is not exit, or 0 if it exit
 */
int kill_shell(char **tokens)
{
	if (strcmp(tokens[0], "exit") == 0)
	{
		free_array(tokens);
		exit(0);
	}
	return (1);
}
