#include "shell.h"
/**
  * _strcat - Concatenates two strings
  * @dest: The destination string
  * @src: The source string
  *
  * Return: A pointer to the resulting string dest
  */
char *_strcat(char *dest, char *src)
{
	int dlen = 0, i = 0;

	while (dest[dlen])
		dlen++;
	for (i = 0; src[i] != '\0'; i++)
	{
		dest[dlen] = src[i];
		dlen++;
	}
	dest[dlen] = '\0';
	return (dest);
}

/**
  * _strstr - locate a substring
  * @haystack: the string to search
  * @needle: the string to find
  *
  * Return: char value
  */
char *_strstr(const char *haystack, const char *needle)
{
	if (*needle == '\0')
	{
		return((char *)haystack);
	}
	while (*haystack != '\0')
	{
		const char *h = haystack;
		const char *n = needle;
		while (*n != '\0' && *h == *n)
		{
			h++;
			n++;
		}
		if (*n == '\0')
		{
			return ((char *)haystack);
		}
		haystack++;
	}
	return (NULL);
}

/**
 * _strcspn - computes the length of the
 * @s1: string to check
 * @s2: string useful to compare
 * Return: the length of the segment.
 **/
size_t _strcspn(const char *s1, const char *s2)
{
	size_t len = 0;
	const char *str = s1;

	while (*str)
	{
		const char *reject = s2;
		while (*reject)
		{
			if (*str == *reject)
			{
				return (len);
			}
			reject++;
		}
		str++;
		len++;
	}
	return (len);
}

/**
  * _strcpy - Copy a string
  * @dest: Destination value
  * @src: Source value
  *
  * Return: the pointer to dest
  */
char *_strcpy(char *dest, const char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}

	dest[i] = '\0';

	return (dest);
}

/**
 * _strncpy - entry point
 * @dest: args
 * @src: args
 * @n: args
 * Return: returns dest
 */
char *_strncpy(char *dest, const char *src, size_t n)
{
	char *d = dest;
	const char *s = src;
	while (n > 0 && *s != '\0')
	{
		*d++ = *s++;
		n--;
	}
	while (n > 0)
	{
		*d++ = '\0';
		n--;
	}
	return (dest);
}
