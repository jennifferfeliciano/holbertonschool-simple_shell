#include "simple_shell.h"

/**
 * path - Function that gets the path from environment.
 * @env: Environment variables.
 * Return: A string of environment paths, or NULL.
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



/**
 * add_path - Concatenates the command with directories in PATH.
 *
 * @tokens: Array of tokens representing the command and its arguments.
 * @path_tok: Array of directories in PATH.
 *
 * Return: Returns the concatenated command path.
 *
 * Description: This function attempts to concatenate the given command
 * with each directory in the path_tok array. It checks if the resulting
 * path corresponds to an existing file. If a valid path is found, it
 * updates the tokens array and returns the updated command path.
 */
char *add_path(char **command, char **path_tok)
{
    char *full_path = NULL;
    int i = 0;
    struct stat stat_buf;

    while (path_tok[i])
    {
        size_t cmd_len = strlen(path_tok[i]) + strlen(command[0]) + 2;
        full_path = malloc(cmd_len);

        if (full_path == NULL)
        {
            perror("malloc error");
            exit(EXIT_FAILURE);
        }

        snprintf(full_path, cmd_len, "%s/%s", path_tok[i], command[0]);

        if (stat(full_path, &stat_buf) == 0)
        {
            break;
        }

        free(full_path);
        i++;
    }

    return full_path;
}

