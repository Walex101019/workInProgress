#include "shell.h"
/**
 * main - entry point
 * Return: 0
*/
int main(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t characters_read;

	while (1)
	{
		printf("WalexShell :) ");
		characters_read = my_getline(&buffer, &bufsize, 0);

		if (characters_read == -1)
		{
			if (feof(stdin)) /* Handle Ctrl+D (end of file) */
			{
				printf("\n");
				free(buffer);
				exit(EXIT_SUCCESS);
			}
			perror("my_getline");
			exit(EXIT_FAILURE);
		}
		/* Remove the newline character from the end of the input */
		if (buffer[characters_read - 1] == '\n')
		{
			buffer[characters_read - 1] = '\0';
		}
		/* Preprocess the user input (replace variables and remove comments) */
		replace_variables(buffer);
		/* Handle built-in commands */
		if (_strcmp(buffer, "env") == 0)
		{
			/* Handle the "env" command */
			handle_env();
		}
		else if (_strstr(buffer, "setenv") == buffer)
		{
			/* Handle the "setenv" command */
			handle_setenv(buffer);
		}
		else if (_strstr(buffer, "unsetenv") == buffer)
		{
			/* Handle the "unsetenv" command */
			handle_unsetenv(buffer);
		}
		else if (_strstr(buffer, "cd") == buffer)
		{
			/* Handle the "cd" command */
			handle_cd(buffer);
		}
		else if (_strstr(buffer, "alias") == buffer)
		{
			/* Handle the "alias" command */
			handle_alias(buffer);
		}
		else if (_strstr(buffer, "&&") || strstr(buffer, "||"))
		{
			/* Handle commands with logical operators */
			execute_logic_operator(buffer);
		}
		else
		{
			/* Execute the command in a child process */
			execute_command(buffer);
		}
		free(buffer);
	}
	return (0);
}
