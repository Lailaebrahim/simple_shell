#include "shell.h"
/**
 * _strncmp - Compares two strings up to a specified number of characters.
 * @s1:The first string to compare.
 * @s2:The second string to compare.
 * @n:The maximum number of characters to compare.
 * Return:0 if the first 'n' characters of 's1' and 's2' are equal,
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
if (s1 == NULL || s2 == NULL)
return (1);
while (n > 0)
{
if (*s1 != *s2)
return ((*s1 > *s2) ? 1 : -1);
else if (*s1 == '\0')
return (0);
s1++;
s2++;
n--;
}
return (0);
}

/**
 * _strchr - Locate first occurance of char in a string
 * @s: The string to search
 * @c: The character to find
 *Return: pointer to first occurance of char of NULL
 */
char *_strchr(const char *s, int c)
{
while (*s != '\0')
{
if (*s == c)
return ((char *)s);
s++;
}
return (NULL);
}
