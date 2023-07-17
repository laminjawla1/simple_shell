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

/*Function Prototypes*/
void display_prompt(char *prompt);
char **tokenize(char *line, char *sep);
size_t get_number_of_tokens(char *line, char *sep);
void free_argv(char **argv);
void execute(char **argv, char *cmd);
char *_which(char *command);
void signal_handler(int sig);
void print_error_msg(int fd, char *error_msg);
#endif
