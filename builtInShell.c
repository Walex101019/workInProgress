#include "shell.h"
/**
 * env_builtin - Handle the "env" built-in command.
 */
void env_builtin(void)
{
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}

/**
 * setenv_builtin - Handle the "setenv" built-in command.
 * @args: An array of command arguments.
 */
void setenv_builtin(char *args[])
{
	if (args[1] != NULL && args[2] != NULL)
	{
		if (setenv(args[1], args[2], 1) != 0)
		{
			perror("setenv");
		}
	}
	else
	{
		fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
	}
}

/**
 * unsetenv_builtin - Handle the "unsetenv" built-in command.
 * @args: An array of command arguments.
 */
void unsetenv_builtin(char *args[])
{
	if (args[1] != NULL)
	{
		if (unsetenv(args[1]) != 0)
		{
			perror("unsetenv");
		}
	}
	else
	{
		fprintf(stderr, "Usage: unsetenv VARIABLE\n");
	}
}

/**
 * cd_builtin - Handle the "cd" built-in command.
 * @args: An array of command arguments.
 */
void cd_builtin(char *args[])
{
	char *new_directory = args[1];

	if (new_directory == NULL)
	{
		new_directory = getenv("HOME");
	}
	else if (_strcmp(new_directory, "-") == 0)
	{
		new_directory = getenv("OLDPWD");
	}
	if (chdir(new_directory) == -1)
	{
		perror("chdir");
	}
	else
	{
		char current_directory[1024];

		getcwd(current_directory, sizeof(current_directory));
		setenv("PWD", current_directory, 1);
		setenv("OLDPWD", new_directory, 1);
	}
}
