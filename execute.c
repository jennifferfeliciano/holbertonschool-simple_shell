#include "simple_shell.h"

/**
 * execution - Compares and executes the command.
 *
 * @tokens: Array of tokens representing the command and its arguments.
 * @env: Environment variables.
 *
 * Return: Always returns 1.
 *
 * Description: This function checks if the given command exists in the
 * current directory or in directories specified by the PATH environment
 * variable. If the command is found, it is executed in a child process.
 */
int execution(char **tokens, char **env)
{
	pid_t child_pid;
	int status;
	struct stat stat_buf;

	/* Check if the command exists in the current directory */
	if (stat(tokens[0], &stat_buf) != 0)
	{
		/* Get the directories in PATH and tokenize them */
		char *path_tok = path(env);
		char **cmd = tokenization(path_tok, ":");

		free(path_tok);
		tokens[0] = add_path(tokens, cmd);/* Attempt to find the command in PATH */
		if (stat(tokens[0], &stat_buf) != 0)/* If the command is not found in PATH */
		{
			free_array(cmd);
			free_array(tokens);
			perror("command not found");
			return (0);
		}
	}
	child_pid = fork(); /* Fork a child process to execute the command */

	if (child_pid == -1)
		perror("Child process failed");
	else if (child_pid == 0)/* Execute the command in the child process */
	{
		if (execve(tokens[0], tokens, env) == -1)
			perror(tokens[0]);
	}
	else
		wait(&status);
	free_array(tokens);
	return (1);
}
