#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>

char **tokenization(char *str, char *delim);
int execution(char **tokens, char **env);
char *path(char **env);
char *add_path(char **tokens, char **path_tok);
int die(char **tokens);
int is_interactive_mode(void);
void free_array(char **tokens);
void handle_non_interactive_mode(int ac, char **av, char **env);
void handle_interactive_shell(char **env);

#endif
