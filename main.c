#include "simple_shell.h"

int main(int ac, char **av, char **env)
{
	char *ptr = NULL, **tokens = NULL;
	size_t n = 0;

	(void)ac;
	(void)av;

	while (1)
	{
		tokens = NULL;
		ptr = NULL;
		n = 0;
		if (isatty(0))
			write(1, "$ ", 2);
		if (getline(&ptr, &n, stdin) == EOF)
		{
			free(ptr);
			exit(EXIT_SUCCESS);
		}
		tokens = tokenization(ptr, " \n");
		free(ptr);

		if (tokens[0] != NULL)
			handle_commands(tokens, env);
		else
			free(tokens);
	}
	free_array(tokens);
	free(ptr);
	return (0);
}
