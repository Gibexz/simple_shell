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

int main(int argc, char **argv);
void exit_code_check(char *command, char **args);

#endif
