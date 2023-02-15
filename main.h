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
void exit_command_check(char *arg0, char *arg1);

#endif
