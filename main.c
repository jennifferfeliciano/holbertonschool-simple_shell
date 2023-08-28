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
	int status = 1;
	ssize_t read;
	size_t size = 0;
	int running = 1;

	while (running)
	{
		write(1, "$ ", 2);
		read = getline(&line, &size, stdin);
		if (read == -1)
			break;
		args = tokenization(line, " \n");


		if (kill_shell(args))
		{
			running = 0;
		}
		else
			status = handle_commands(args, env);


	}
	free_array(args);
	free(line);
	exit(status);
}

/**
 * noninteractive_shell - Main loop of a non-interactive shell
 * @env: Array of strings representing environment variables
 * Return: void
 */

void noninteractive_shell(char **env)
{
	char *line = NULL;
	char **args;
	size_t size = 0;
	int status = 0;
	ssize_t read;

	read = getline(&line, &size, stdin);
	if (read != -1)
	{
		args = tokenization(line, " \n");

		if (kill_shell(args))
		{
			free(line);
			free_array(args);
			exit(status);
		}

		status = handle_commands(args, env);

			free(line);
		free(args);
	}

		free(line);
	free_array(args);
}

exit(status);
}
