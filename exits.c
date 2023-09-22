#include "shell.h"
/**
 * exit_builtin - Handle the "exit" built-in command.
 * @args: An array of command arguments.
 */
void exit_builtin(char *args[])
{
	if (args[1] != NULL)
	{
		int status = atoi(args[1]);

		exit(status);
	}
	else
	{
		exit(EXIT_SUCCESS);
	}
}
