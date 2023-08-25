#include "simple_shell.h"



char *get_line() 
{
    char *line = NULL;
    size_t bufsize = 0;

    /*Use getline to read the input line */
    ssize_t n_chars = getline(&line, &bufsize, stdin);

    /*Check for errors or end of input */ 
    if (n_chars == -1)
    {
        free(line);
        line = NULL;
    }
    else if (line[n_chars - 1] == '\n')
    {
        /*Remove the newline character */ 
        line[n_chars - 1] = '\0';
    }

    return line;
}
