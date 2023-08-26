#include "simple_shell.h"



char *get_line() 
{
    char *line = NULL;
    size_t bufsize = 0;

    /*Use getline to read the input line */
    getline(&line, &bufsize, stdin);

    return line;
}
