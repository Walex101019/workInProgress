#include "shell.h"
/**
 * execute_command - entry point
 * @command: passed
 * Return: return
*/
int execute_command(char *command)
{
	pid_t child_pid = fork();
	int status;

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		char *args[64];

		custom_tokenize(command, args, 64, ' ');
		execvp(args[0], args);
		perror("execvp");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
		return (WEXITSTATUS(status));
	}
}

/**
 * execute_logic_operator - entry point
 * @command: args passed
 * Return: return
*/
int execute_logic_operator(char *command)
{
	char *left_command = strtok(command, "&&||");
	char *logical_operator = strtok(NULL, "&&||");
	char *right_command = strtok(NULL, "&&||");
	int status_left = execute_command(left_command);

	if (left_command == NULL || logical_operator == NULL || right_command == NULL)
	{
		fprintf(stderr, "Invalid usage of logical operator\n");
		return (1);
	}
	if (_strcmp(logical_operator, "&&") == 0)
	{
		if (status_left == 0)
		{
			int status_right = execute_command(right_command);

			return (status_right);
		}
		else
		{
			return (status_left);
		}
	}
	else if (_strcmp(logical_operator, "||") == 0)
	{
		if (status_left != 0)
		{
			int status_right = execute_command(right_command);

			return (status_right);
		}
		else
		{
			return (status_left);
		}
	}
	else
	{
		fprintf(stderr, "Invalid logical operator: %s\n", logical_operator);
		return (1);
	}
}

