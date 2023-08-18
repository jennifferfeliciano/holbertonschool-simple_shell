#include "simple_shell.h"

/**
 * main - Runs the simple shell program.
 *
 * @ac: Argument count.
 * @av: Argument vector.
 * @env: Environment variables.
 *
 * Return: Always returns 0.
 *
 * Description: This program runs an interactive shell that reads user input,
 * processes the input, and executes commands. It provides a prompt, tokenizes
 * input, handles built-in commands, and executes external commands.
 */
int main(int ac __attribute__((unused)), char **av, char **env)
{
    char *ptr = NULL, **tokens = NULL;
    size_t n = 0;
    int i;

    (void)av;

    while (1)
    {
        tokens = NULL;
        ptr = NULL;
        n = 0;

        /* Display prompt if running in interactive mode */
        if (isatty(0))
            write(1, "$ ", 2);

        /* Read user input */
        if (getline(&ptr, &n, stdin) == EOF)
        {
            free(ptr);
            exit(EXIT_SUCCESS);
        }

        /* Tokenize the input string */
        tokens = tokenization(ptr, " \n");
        free(ptr);

        if (tokens[0] != NULL)
        {
            /* Handle built-in command "env" */
            if (strcmp(tokens[0], "env") == 0)
            {
                for (i = 0; env[i]; i++)
                {
                    write(1, env[i], strlen(env[i]));
                    write(1, "\n", 1);
                }
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

    free_array(tokens);
    free(ptr);

    return (0);
}