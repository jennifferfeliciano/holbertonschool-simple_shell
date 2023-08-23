#include "simple_shell.h"

/**
 * handle_non_interactive_mode - Handle commands in non-interactive mode.
 *
 * @ac: Argument count.
 * @av: Argument vector.
 * @env: Environment variables.
 */
void handle_non_interactive_mode(int ac, char **av, char **env)
{
    char *ptr = NULL, **tokens = NULL;
    int i;

    for (i = 1; i < ac; i++)
    {
        ptr = av[i];
        tokens = tokenization(ptr, " \n");
        if (tokens[0] != NULL)
        {
            if (die(tokens) == 1)
                execution(tokens, env);
        }
        free_array(tokens);
    }
}
