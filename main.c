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
	char *line = NULL;
	char **args;
	int status = 1;
	ssize_t read = 0;
	size_t size = 0;


	while (status)
	{
		write(1, "$ ", 2);
		read = getline(&line, &size, stdin);
		if (read == -1)
			break;
		args = tokenization(line, " \n");


		if (args[0] != NULL && strcmp(args[0], "exit") == 0)
        {
            free(line);
            free_array(args);
			exit(0);
        }
		status = handle_commands(args, env);

	}
	free(line);


}

void noninteractive_shell(char **env)
{
	char *line = NULL;
	char **args;
	ssize_t read = 0;
	size_t size = 0;
	
	read = getline(&line, &size, stdin);


	args = tokenization(line, " \n");


	if ((args[0] != NULL && strcmp(args[0], "exit") == 0 )| (read == -1))
    {
    free(line);
    free_array(args);
	exit(0);
    }

	handle_commands(args, env);
	
	free(line);
    free_array(args);


}

