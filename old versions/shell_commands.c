#include "simple_shell.h"

/**
 * handle_env_command - Handle the "env" built-in command.
 *
 * @env: Environment variables.
 */
void handle_env_command(char **env)
{
    int i;

    for (i = 0; env[i]; i++)
    {
        write(1, env[i], strlen(env[i]));
        write(1, "\n", 1);
    }
}

/**
 * handle_interactive_shell - Handle commands in interactive shell mode.
 *
 * @env: Environment variables.
 */
void handle_interactive_shell(char **env)
{
    char *input = NULL, **tokens = NULL;
    size_t n = 0;



    while (1)
    {
        tokens = NULL;
        input = NULL;
        n = 0;

        /* Display prompt */
        write(1, "$ ", 2);

        /* Read user input */
        if (getline(&input, &n, stdin) == EOF)
        {
            free(input);
            exit(EXIT_SUCCESS);
        }

        tokens = tokenization(input, " \n");
        free(input);

        if (tokens[0] != NULL)
        {
            /* Handle built-in command "env" */
            if (strcmp(tokens[0], "env") == 0)
            {
                handle_env_command(env);
                free_array(tokens);
                continue;
            }

            /* Check if the command is not "exit" */
            if (die(tokens) == 1)
                execution(tokens, env);
        }
        else
            free_array(tokens);
    }
}