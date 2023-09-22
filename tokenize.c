#include "shell.h"
/**
 * custom_tokenize - Custom tokenization function
 * @str: The input string to tokenize.
 * @tokens: An array of strings to store the tokens.
 * @max_tokens: The maximum number of tokens to extract.
 * @delimiter: The delimiter character to split the input.
 *
 * Return: The number of tokens found.
 */
int custom_tokenize(const char *str, char *tokens[], int max_tokens, char delimiter)
{
	int token_count = 0;
	const char *input_start = str;
	const char *input_end = str;
	char current_char;

	while (1)
	{
		current_char = *input_end;

		if (current_char == delimiter || current_char == '\0')
		{
			int token_length = input_end - input_start;

			if (token_length > 0)
			{
				tokens[token_count] = (char *)malloc(token_length + 1);
				if (tokens[token_count] == NULL)
				{
					perror("malloc");
					exit(EXIT_FAILURE);
				}
				strncpy(tokens[token_count], input_start, token_length);
				tokens[token_count][token_length] = '\0';
				token_count++;
				if (token_count >= max_tokens)
				{
					break;
				}
			}
			if (current_char == '\0')
			{
				break;
			}
			input_start = input_end + 1;
		}
		input_end++;
	}
	return (token_count);
}
