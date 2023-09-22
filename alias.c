#include "shell.h"
static struct Alias aliases[MAX_ALIASES];
static int alias_count;
/**
 * find_alias - entry
 * @name: args
 * Return: returns -1
*/
int find_alias(const char *name)
{
	int i;

	for (i = 0; i < alias_count; i++)
	{
		if (_strcmp(aliases[i].name, name) == 0)
		{
			return (i);
		}
	}
	return (-1);
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
		printf("%s='%s'\n", aliases[i].name, aliases[i].value);
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
		int index = find_alias(names[i]);

		if (index != -1)
		{
			printf("%s='%s'\n", aliases[index].name, aliases[index].value);
		}
	}
}
/**
 * define_aliases - entry
 * @aliases: args
*/
void define_aliases(char *aliases[])
{
	int i;

	for (i = 0; aliases[i] != NULL; i++)
	{
		char *name = aliases[i];
		char *value = _strchr(name, '=');
		int index;

		if (value != NULL)
		{
			*value = '\0';
			value++;
			index = find_alias(name);

			if (index != -1)
			{
				free(aliases[index].value);
				aliases[index].value = _strdup(value);
			}
			else
			{
				if (alias_count < MAX_ALIASES)
				{
					_strncpy(aliases[alias_count].name, name, MAX_ALIAS_NAME_LENGTH -1);
					_strncpy(aliases[alias_count].value, value MAX_ALIAS_VALUE_LENGTH -1);
					alias_count++;
				}
				else
				{
					fprintf(stderr, "Alias limit reached. Cannot define more aliases.\n");
				}
			}
		}
		else
		{
			fprintf(stderr, "Invalid alias syntax: %s\n", name);
		}
	}
}
