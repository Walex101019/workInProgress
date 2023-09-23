#include "shell.h"
/**
 * find_alias - entry
 * @argc: arg
 * @argv: args
 * Return: returns -1
*/
int find_alias(int argc, char*argv[])
{
	if (argc == 1)
	{
		print_aliases();
	}
	else
	{
		int 1;
		for (i = 1, i < argc; i++)
		{
			if (_strchr(argv[i], '='))
			{
				char *name = strtok(argv[i], "=");
				char *value = strtok(NULL, "=");

				if (name && value)
				{
					define_alias(name, value);
				}
				else
				{
					fprintf(stderr, "Invalid alias syntax: %s\n", argv[i])
				}
			}
			else
			{
				print_alias(argv[i]);
			}

		}
	}
}
/**
 * list_aliases - entry point
 * Void return
*/
void list_aliases(void)
{
	int i;

	for (i = 0; i < alias_count; i++)
	{
		printf("%s='%s'\n", Alias[i].name, aliases[i].value);
	}
}
/**
 * print_aliases - entry point
 * @names: args
*/
void print_aliases(char *names[])
{
	int i;

	for (i = 0; names[i] != NULL; i++)
	{
		if (_strcmp(names, aliases[i].name) == 0)
		{
			printf("%s='%s'\n", aliases[i].name, aliases[i].value);
			return;
		}
	}
	fprintf(stderr, "Alias not found: %s\n", name);
}
/**
 * define_aliases - entry
 * @name: args
 * @value: args
*/
void define_aliases(const char *name, const char *value)
{
	int i;

	for (i = 0; i < alias_count; i++)
	{
		if (_strcmp(name, aliases[i].name) == 0)
		{
			free(aliases[i].value);
			aliases[i].value = _strdup(value);
			return;
		}
	}
	if (alias_count < MAX_ALIASES)
	{
		aliases[alias_count].name = _strdup(name);
		aliases[alias_count].value = _strdup(value);
		alias_count++;
	}
	else
	{
		fprintf(stderr, "Maximum alias limit reached (%d)\n", MAX_ALIASES);
	}
}
