#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define TOKEN_Delimitator ":"

char **tokenization(char *ptr, char *delim);
int execution(char **tokens, char **env);
char *path(char **env);
char *add_path(char **tokens, char **path_tok);
int kill_shell(char **tokens);
void free_array(char **tokens);
void handle_env_command(char **env);
int handle_commands(char **tokens, char **env);

void interactive_shell(char **env);
void noninteractive_shell(char **env);
char *get_line();

#endif
