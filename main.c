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
            free(line);
            free_array(args);
            running = 0;
        }
		else
			status = handle_commands(args, env);
		
		
        free(line);
        free_array(args);
    }
	exit(status);
}

void noninteractive_shell(char **env)
{
    char *line = NULL;
    char **args;
    size_t size = 0;
    int status = 0;
    ssize_t read;

    if ((read = getline(&line, &size, stdin)) != -1)
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
        free_array(args);
    }

    exit(status);
}

