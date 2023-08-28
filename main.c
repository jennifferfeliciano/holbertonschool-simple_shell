#include "simple_shell.h"

/**
 * main- Entry point
 * @ac: The number of arguments
 * @av: An array of strings containing the arguments
 * @env: Environment variables
 * Return: EXIT_SUCCESS if  successful completion
 */

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;

	if (!isatty(0))
		noninteractive_shell(env);
	else
		interactive_shell(env);


	return (EXIT_SUCCESS);

}

/**
 * interactive_shell - Main loop of an interactive shell
 * @env: Array of strings representing environment variables
 * Return: void
 */

void interactive_shell(char **env)
{
	char *line;
	char **args;
	int status;

	while (status)
	{
		write(1, "$ ", 2);
		line = get_line();
		args = tokenization(line, " \n");
		status = handle_commands(args, env);

		free(line);
		free(args);
	}
}

/**
 * noninteractive_shell - Main loop of a non-interactive shell
 * @env: Array of strings representing environment variables
 * Return: void
 */

void noninteractive_shell(char **env)
{
	char *line;
	char **args;
	int status;

	while (status)
	{
		line = get_line();
		args = tokenization(line, " \n");
		status = handle_commands(args, env);

		free(line);
		free(args);
	}


}

