#include "shell.h"
/**
 * main - entry point
 * @argc: arguement passed
 * @argv: arguement passed
 * Return: return
*/
int main(int argc, char *argv[])
{
	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t characters_read;
	int status = EXIT_SUCCESS;

	if (argc > 1)
	{
		status = execute_from_file(argv[1]);
		if (status != EXIT_SUCCESS)
		{
			fprintf(stderr, "Error executing commands from the file.\n");
			return (EXIT_FAILURE);
		}
	}
	else
	{
		while (1)
		{
			display_prompt();
			characters_read = my_getline(&buffer, &bufsize, 0);

			if (characters_read == -1)
			{
				if (feof(stdin))
				{
					printf("\n");
					free(buffer);
					exit(EXIT_SUCCESS);
				}
				perror("my_getline");
				exit(EXIT_FAILURE);
			}
			if (buffer[characters_read - 1] == '\n')
			{
				buffer[characters_read - 1] = '\0';
			}
			replace_variables(buffer);
			if (_strcmp(buffer, "env") == 0)
			{
				handle_env();
			}
			else if (_strstr(buffer, "setenv") == buffer)
			{
				handle_setenv(buffer);
			}
			else if (_strstr(buffer, "unsetenv") == buffer)
			{
				handle_unsetenv(buffer);
			}
			else if (_strstr(buffer, "cd") == buffer)
			{
				handle_cd(buffer);
			}
			else if (_strstr(buffer, "alias") == buffer)
			{
				handle_alias(buffer);
			}
			else if (_strstr(buffer, "&&") || strstr(buffer, "||"))
			{
				execute_logic_operator(buffer);
			}
			else
			{
				execute_command(buffer);
			}
			free(buffer);
		}
	}
	return (status);
}
