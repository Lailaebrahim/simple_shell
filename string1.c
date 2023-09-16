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

/**
 * _atoi - converts a string to an integer
 * @str: input string
 * Return: integer
 */
int _atoi(const char *str)
{
int res = 0;
int sign = 1;
int i = 0;

while (str[i] == ' ')
i++;

if (str[0] == '-')
{
sign = -1;
i++;
}

for (; str[i] != '\0'; ++i)
{
if (str[i] >= '0' && str[i] <= '9')
res = res * 10 + (str[i] - '0');
else
continue;
}

return (sign *res);
}

/**
 * _strcat - Concat Two String
 * @dest:First String
 * @src:Second String
 * Return:First String + Second String Char *
 */
char *_strcat(char *dest, char *src)
{

char *s = dest;

while (*dest != '\0')
{
dest++;
}

while (*src != '\0')
{
*dest = *src;
dest++;
src++;
}
*dest = '\0';
return (s);
}
