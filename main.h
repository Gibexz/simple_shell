#ifndef MAIN_H
#define MAIN_H

/*define evironment */
extern char **environ;

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdbool.h>
#include <sys/stat.h>

int main(int argc, char **argv);
void command_code_check(char *command, char **args, int argc, char **argv);
char **tokens_array(char *cmd_input, int *word_Count);
char *cmd_check(char **args);
void fork_process(pid_t process, char **args, char **argv);
ssize_t _getline(char **command, size_t *buffsize, FILE* stream);
char *_strtok(char *str, const char *delim);

/* In command_code_ check */
void _setenv(char **args, int argc, char **argv);
void _unsetenv(char **args, int argc, char **argv);
void exit_code(char *command, char **args);
void print_env(char **env);
/*void do_setenv(char **args);*/

#endif
