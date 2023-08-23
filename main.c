#include "simple_shell.h"

int main(int ac, char **av, char **env)
{
    if (ac > 1)
    {
        handle_non_interactive_mode(ac, av, env);
    }
    else
    {
        handle_interactive_shell(env);
    }

    return (0);
}