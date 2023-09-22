#include "shell.h"
/**
 * replace_variables - entry point
 * @command: arg passed
 * Void return
*/
void replace_variables(char *command)
{
	char *pos = strstr(command, "$?");
	char *comment_start = _strchr(command, '#');

	if (pos != NULL)
	{
		int exit_status = WEXITSTATUS(system(NULL));
		char exit_status_str[12];

		snprintf(exit_status_str, sizeof(exit_status_str), "%d", exit_status);
		command = strdup_replace(command, "$?", exit_status_str);
	}
	pos = strstr(command, "$$");
	if (pos != NULL)
	{
		pid_t shell_pid = getpid();

		char pid_str[12];

		snprintf(pid_str, sizeof(pid_str), "%d", shell_pid);
		command = strdup_replace(command, "$$", pid_str);
	}
	if (comment_start != NULL)
	{
		*comment_start = '\0';
	}
}

/**
 * strdup_replace - entry
 * @original: arg pass
 * @pattern: arg passed
 * @replacement: arg passed
 * Return: return
*/
char *strdup_replace(const char *original, const char *pattern, const char *replacement)
{
	char *result;
	const char *ins;
	char *tmp;
	int len_pattern = _strlen(pattern);
	int len_replacement = _strlen(replacement);
	int count;

	if (!pattern || !replacement)
	{
		return (_strdup(original));
	}
	len_pattern = _strlen(pattern);

	for (count = 0, ins = original; (tmp = _strstr(ins, pattern)); ++count, ins = tmp + len_pattern)
		;
	tmp = result = (char *)malloc(_strlen(original) + (len_replacement - len_pattern) * count + 1);
	if (!result)
	{
		return (NULL);
	}
	while (count--)
	{
		ins = _strstr(original, pattern);
		len_replacement = ins - original;
		tmp = strncpy(tmp, original, len_replacement) + len_replacement;
		tmp = _strcpy(tmp, replacement) + len_replacement;
		original += len_replacement + len_pattern;
	}
	_strcpy(tmp, original);
	return (result);
}
