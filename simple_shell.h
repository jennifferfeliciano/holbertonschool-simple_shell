#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>

/* String functions */
char **tokenization(char *str, char *delim);

/* Path handling */
char *add_path(char **tokens, char **path_tok);

/* Execution */
int execution(char **tokens, char **env);
int die(char **tokens);
void free_array(char **tokens);

#endif /* SIMPLE_SHELL_H */
