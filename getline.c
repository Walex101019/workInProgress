#include "shell.h"
static char buffer[READ_SIZE];
static size_t buffer_size;
static size_t buffer_pos;
/*
 * my_getline - entry point
 * @lineptr: arguement
 * @n: arguement
 * @fd: arguement
 * Return: return
 */
ssize_t my_getline(char **lineptr, size_t *n, int fd)
{
	ssize_t total_bytes = 0;
	char *line = NULL;
	char current_char = buffer[buffer_pos++];

	if (lineptr == NULL || n == NULL)
	{
		return (-1);
	}
	while (1)
	{
		if (buffer_pos >= buffer_size)
		{
			buffer_size = read(fd, buffer, READ_SIZE);
			if (buffer_size <= 0)
			{
				if (line != NULL)
				{
					free(line);
					line = NULL;
				}
				if (total_bytes == 0)
				{
					return (-1);
				}
				break;
			}
			buffer_pos = 0;
		}
		if ((size_t)total_bytes >= *n)
		{
			size_t new_size = *n * 2;
			char *new_line = realloc(line, new_size);

			if (new_line == NULL)
			{
				if (line != NULL)
				{
					free(line);
				}
				return (-1);
			}
			line = new_line;
			*n = new_size;
		}
		line[total_bytes++] = current_char;

		if (current_char == '\n')
		{
			break;
		}
	}
	if (line != NULL)
	{
		line[total_bytes] = '\0';
		*lineptr = line;
	}
	return (total_bytes);
}
