#include "simple_shell.h"

/**
 * get_line - Read a line of input from standard input
 * Return: Pointer to the allocated input line or NULL if error or end of input
 */

char *get_line()
{
	char *line = NULL;
	size_t bufsize = 0;

	/*Use getline to read the input line */
	ssize_t n_chars = getline(&line, &bufsize, stdin);

	if (n_chars == -1)
	{
		free(line);
		line = NULL;
	}
	else if (line[n_chars - 1] == '\n')
	{
		line[n_chars - 1] = '\0';
	}

	return (line);
}
