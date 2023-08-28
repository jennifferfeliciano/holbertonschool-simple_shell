#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>

void interactive_shell(char **env);
void noninteractive_shell(char **env);

int handle_commands(char **tokens, char **env);
void handle_env_command(char **env);

char **tokenization(char *ptr, char *delim);

int execution(char **tokens, char **env);
char *path(char **env);
char *add_path(char **command, char **path_tok);

void free_array(char **tokens);
int kill_shell(char **tokens);



#endif
