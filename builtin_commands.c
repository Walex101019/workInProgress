#include "shell.h"
/**
 * handle_env - entry
*/
void handle_env(void)
{
	env_builtin();
}

/**
 * handle_setenv - entry
 * @buffer: arg
*/
void handle_setenv(char *buffer)
{
	char *args[3];

	args[0] = "setenv";
	custom_tokenize(buffer, args, 3, ' ');
	setenv_builtin(args);
}

/**
 * handle_unsetenv - entry
 * @buffer: arg
*/
void handle_unsetenv(char *buffer)
{
	char *args[2];

	args[0] = "unsetenv";
	custom_tokenize(buffer, args, 2, ' ');
	unsetenv_builtin(args);
}

/**
 * handle_cd - entry
 * @buffer: arg
*/
void handle_cd(char *buffer)
{
	char *args[2];

	args[0] = "cd";
	custom_tokenize(buffer, args, 2, ' ');
	cd_builtin(args);
}

/**
 * handle_alias - entry
 * @buffer: arg
*/
void handle_alias(char *buffer)
{
	char *args[64];
	int arg_count = 0;
	int i;

	custom_tokenize(buffer, args, 64, ' ');
	/* Remove the "alias" token from the arguments */
	while (args[arg_count] != NULL)
	{
		arg_count++;
	}
	for (i = 0; i < arg_count - 1; i++)
	{
		args[i] = args[i + 1];
	}
	args[arg_count - 1] = NULL;
	/* Check if the "alias" command has arguments */
	if (args[0] == NULL)
	{
		/* List all aliases if no arguments provided */
		list_aliases();
	}
	else
	{
		/* Handle alias commands (printing or defining) */
		if (strchr(args[0], '=') != NULL)
		{
			/* Define new aliases */
			define_aliases(const char *name, const char *value);
		}
		else
		{
			/* Print specific aliases */
			print_aliases(args);
		}
	}
}
