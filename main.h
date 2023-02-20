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
void exit_code_check(char *command, char **args);
char **tokens_array(char *cmd_input, int *word_Count);
char *cmd_check(char **args);
void fork_process(pid_t process, int word_Count, char **args, char **argv);
ssize_t _getline(char **command, size_t *buffsize, FILE* stream);

#endif
