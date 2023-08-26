#include "simple_shell.h"

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

void interactive_shell(char **env)
{
	char *line;
	char **args;
	int status = 1;

	while (status)
	{
		write(1, "$ ", 2);
		line = get_line();
		args = tokenization(line, " \n");
		status = handle_commands(args, env);

		free(line);
		free_array(args);
	}
}

void noninteractive_shell(char **env)
{
	char *line;
	char **args;

	
		line = get_line();
		args = tokenization(line, " \n");
		handle_commands(args, env);

		free(line);
		free(args);

}

