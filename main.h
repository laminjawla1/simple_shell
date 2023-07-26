#ifndef MAIN_H
#define MAIN_H

/*Header Files*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
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
void print_error_msg(char *s_name, char *p_name, char *ec, size_t count);
char *_getline(int fd);
int execute_from_file(char **argv);
void execute_semicolon_sep(char *user_input, char *s_name, int n);

/*Built in function prototypes*/
int (*reference_builtin(char *cmd))(char **argv, char *user_input);
int exit_shell(char **argv, char *user_input);
int print_env(char **argv, char *user_input);

/*Miscellaneous functions*/
bool _isdigit(char *s);
char *handle_comments(char *command);

/*String utilities*/
bool _strchr(char *s, char c);
size_t _strlen(char *s);
char *_strdup(char *s);
void _strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
#endif
