#include "simple_shell.h"

/**
 * path - Function that gets the path from environment.
 *
 * @env: Environment variables.
 *
 * Return: A string that contains environment paths, or NULL if it fails.
 *
 * Description: This function searches for the "PATH" environment variable
 * and returns a concatenated string of directories.
 */
char *path(char **env)
{
    int i = 0;
    char *path, **copy_path;

    while (env[i])
    {
        if (strncmp(env[i], "PATH", 4) == 0)
        {
            path = strdup(env[i]);
            copy_path = tokenization(path, "=");
            free(path);
            path = strdup(copy_path[1]);
        }
        i++;
    }

    free_array(copy_path);
    return (path);
}
