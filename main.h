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
#include <stdarg.h>


/**
 * struct print - created stuct troe print_struct
 * @t: pointer to character speccifer
 * @funct: function pointer to check_spec code for the
 * respective character
 */
typedef struct print
{
	char *t;
	int (*funct)(va_list);
} print_struct;

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
unsigned int check_match(char c, const char *str);/* used in _strtok */
/*void do_setenv(char **args);*/

/* string functions and atoi */
int _strlen(char *msg);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
int is_numerical(unsigned int n);
int _atoi(char *s);
void _puts(char *str);

/*Printf files */
int (*check_specifier(const char *format))(va_list);
int _putchar(char c);
int _printf(const char *format, ...);
int print_c(va_list ap);
int print_s(va_list ap);
int print_int(va_list ap);
int print_deci(va_list ap);

#endif
