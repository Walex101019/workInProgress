#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

#define READ_SIZE 1024
#define MAX_ALIAS_NAME_LENGTH 50
#define MAX_ALIAS_VALUE_LENGTH 100
#define MAX_ALIASES 50

/* Structure to store aliases */
struct Alias {
	char name[MAX_ALIAS_NAME_LENGTH];
	char value[MAX_ALIAS_VALUE_LENGTH];
};

/* Function prototypes for built-in commands */
void env_builtin(void);
void setenv_builtin(char *args[]);
void unsetenv_builtin(char *args[]);
void cd_builtin(char *args[]);
void handle_alias(char *buffer);
void exit_builtin(char *args[]);
void handle_env(void);
void display_prompt(void);
void handle_setenv(char *buffer);
void handle_unsetenv(char *buffer);
void handle_cd(char *buffer);
void handle_alias(char *buffer);

/* Function prototypes for logic_operators.c */
int execute_logic_operator(char *command);
void display_prompt(void);
char *_strcat(char *dest, char *src);
int _strcmp(const char *s1, const char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
int _strlen(const char *s);
int execute_from_file(const char *filename);
char *_strdup(const char *str);
char *_strchr(char *s,char c);
size_t _strcspn(const char *s1, const char *s2);
char *_strcpy(char *dest, const char *src);
char *_strstr(const char *haystack, const char *needle);
char *_strncpy(char *dest, const char *src, size_t n);

/* Function prototypes for custom functions (tokenize.c, variable_replacement.c, alias.c) */
ssize_t my_getline(char **lineptr, size_t *n, int fd);
int custom_tokenize(const char *str, char *tokens[], int max_tokens, char delimiter);
void replace_variables(char *buffer);
char *strdup_replace(const char *original, const char *pattern, const char *replacement);
int execute_command(char *command);
int find_alias(const char *name);
void list_aliases(void);
void define_aliases(char *aliases[]);
void print_aliases(char *names[]);

/* Declare the global environment variable */
extern char **environ;

#endif /* SHELL_H */
