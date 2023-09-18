#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>

#define MAX_INPUT_LENGTH 100
#define EXIT_CODE 0

/* Function prototypes */
void sigint_handler(int signum);
void parse_command(char *command, char **args, int *background);

#endif
