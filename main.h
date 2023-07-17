#ifndef MAIN_H
#define MAIN_H

/*Header Files*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>

#define BUFF_SIZE 50

/*The global environmentt variable*/
extern char **environ;

/**
* struct builtin_t - A template for the builtin commands
*
*@name: Name for the builtin command
*@f: A pointer to the function defining the builtin command
*/
typedef struct builtin_t
{
	char *name;
	int (*f)(char **argv, char *line);
} builtint_t;


/*Function Prototypes*/
void display_prompt(char *prompt);
char **tokenize(char *line, char *sep);
size_t get_number_of_tokens(char *line, char *sep);
void free_argv(char **argv);
void execute(char **, char *, char *, size_t);
char *_which(char *command);
void signal_handler(int sig);
void print_error_msg(int fd, char *error_msg);
char *_getline(int fd);
int (*reference_builtin(char *cmd))(char **argv, char *user_input);
int exit_shell(char **argv, char *user_input);
int print_env(char **argv, char *user_input);
#endif
