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