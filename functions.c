#include "simple_shell.h"

/**
 * kill_shell - function that will check if tokens 0 is the word exit
 *
 * @tokens: array of tokens that we will checked only the first tokean
 *
 * Return: 1, if the word is not exit, or 0 if it exit
 */
int kill_shell(char **tokens)
{
	if (strcmp(tokens[0], "exit") == 0)
	{
		return (1); /*Indicate that the program should exit*/
	}
	return (0); /*Indicate that shell should continue*/
}

/**
 * free_array - function to free a array
 * @tokens: array to be free
 * Return: Theres no return. (void)
 */
void free_array(char **tokens)
{
	int i = 0;

	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}

	free(tokens);
}

/**
 * handle_env_command- Handle the "env" built-in command.
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
 *handle_commands- Function to handle the "env" command
 *@tokens: Array of strings representing the command and its arguments
 *@env: Array of strings representing environment variables
 *Return: 1, indicating continued shell loop execution.
 */

int handle_commands(char **tokens, char **env)
{
	if (strcmp(tokens[0], "env") == 0)
	{
		handle_env_command(env);
		free_array(tokens);
	}

	if (kill_shell(tokens) == 1)
		execution(tokens, env);

	free_array(tokens);

	return (1);
	int status = -1;

	if (tokens[0] != NULL && strcmp(tokens[0], "env") == 0)
	{
		handle_env_command(env);
		free_array(tokens);
		return (0);
	}


	status = execution(tokens, env);



	return (status);
}


