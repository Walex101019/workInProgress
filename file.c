#include "shell.h"
/**
 * execute_from_file - Execute commands from a file.
 * @filename: The name of the file containing commands.
 * 
 * Return: 0 on success, -1 on failure.
 */
int execute_from_file(const char *filename)
{
	FILE *file = fopen(filename, "r");
	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t characters_read;
	int status = 0;

	if (file == NULL)
	{
		perror("fopen");
		return (-1);
	}
	while ((characters_read = getline(&buffer, &bufsize, file)) != -1)
	{
		if (characters_read > 0 && buffer[characters_read - 1] == '\n')
		{
			buffer[characters_read - 1] = '\0';
		}
		if (execute_command(buffer) != 0)
		{
			fprintf(stderr, "Error executing command: %s\n", buffer);
			status = -1;
			break;
		}
		free(buffer);
		buffer = NULL;
	}
	fclose(file);
	return (status);
}
