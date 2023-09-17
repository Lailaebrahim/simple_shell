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
 * @name:first string
 * @sep:second string
 *@value: third string 
 *Return: pointer to full concatenated
 */
char *concat_all(char *name, char *sep, char *value)
{
int i = 0, k = 0;
char *res = NULL;
res = malloc(_strlen(name) + _strlen(sep) + _strlen(value) + 1);
if (res == NULL)
return (NULL);
for (i = 0; name[i]; i++)
res[i] = name[i];
k = i;
for (i = 0; sep[i]; i++)
res[k + i] = sep[i];
k = k + i;
for (i = 0; value[i]; i++)
res[k + i] = value[i];
k = k + i;
res[k] = '\0';
return (res);
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

/**
 *my_memset - function to fill n bytes of memory with a value
 *@s:pointer to memory to be filled
 *@c: value to be filled with
 *@len:number of bytes to be filled
 */
void *my_memset(void *s, int c,  unsigned int len)
{
unsigned char* p = s;
while (len--)
{
*p++ = (unsigned char)c;
}
return (s);
}
