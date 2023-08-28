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
char *add_path(char **tokens, char **path_tok)
{
	char *cmd;
	int i = 0;
	struct stat stat_buf;

	while (path_tok[i])
	{
		/* Calculate the length for the concatenated path */
		size_t cmd_len = strlen(path_tok[i]) + strlen(tokens[0]) + 2;

		cmd = malloc(cmd_len);

		if (cmd == NULL)
			return (NULL);  /*Memory allocation failed*/

		/* Concatenate the directory path and command */
		snprintf(cmd, cmd_len, "%s/%s", path_tok[i], tokens[0]);

		/* Check if the concatenated path corresponds to an existing file */
		if (stat(cmd, &stat_buf) == 0)
		{
			tokens[0] = cmd; /* Update the tokens array */
			break;
		}

		free(cmd); /* Free memory if the command does not exist*/
		i++;
	}

	return (tokens[0]);
}

