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

/*Function Prototypes*/
void display_prompt(char *prompt);
char **tokenize(char *line, char *sep);
size_t get_number_of_tokens(char *line, char *sep);
void free_argv(char **argv);
void execute(char **argv, char *p_name);

#endif
