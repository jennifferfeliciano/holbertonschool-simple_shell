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

void handle_commands(char **tokens, char **env)
{

		if (strcmp(tokens[0], "env") == 0)
			{
				handle_env_command(env);
				free_array(tokens);
			}
		
		if (die(tokens) == 1)
				execution(tokens, env);

}
