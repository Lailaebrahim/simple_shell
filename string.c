#include "shell.h"
/**
 * _strlen - a function that returns the length of a string.
 * @s : pointer to a string
 * Return:int length of string
 */
size_t _strlen(const char *s)
{
size_t len = 0;
while (s[len] != '\0')
{
len++;
}
return (len);
}
/**
 * _strcmp - compare two strings
 * @s1 : a pointer to the first string
 * @s2 : a pointer to the string to be compared to first string
 * Return: 0 if they are similar
 * negative value if s1 < s2
 * positive value if s1 > s2
 * this value corresponds to the difference between ascii code
 * of the first different charcter between two strings
 */
int _strcmp(char *s1, char *s2)
{
int i = 0;
int ret = 0;
while (s1[i] != '\0' && s2[i] != '\0')
{
if (s1[i] != s2[i])
{
ret = s1[i] - s2[i];
break;
}
else if (s1[i] == s2[i])
{
ret = 0;
i++;
}
else
{
/*nothing*/
}
}
return (ret);
}
/**
 * _strcpy - a function that copies the string pointed to by src
 * @dest: copy to
 * @src: copy from
 * Return: string
 */
char *_strcpy(char *dest, const char *src)
{
int i = 0;
if (dest == NULL || src == NULL)
return (NULL);
for (i = 0; (i < _strlen( src)) && src[i] != '\0'; i++)
{
dest[i] = src[i];
}
dest[i] = '\0';
return (dest);
}
/**
 * _strncpy - copy a string
 * @dest : a pointer to the string to copy to
 * @src : a pointer to the string to be copied
 * @n : number of bytes to be from src
 * Return: string copied
 */
char *_strncpy(char *dest, const char *src, int n)
{
char *original_dest = dest;
while (*src && n)
{
*dest++ = *src++;
n--;
}
while (n)
{
*dest++ = '\0';
n--;
}
return (original_dest);
}

/**
 * _strdup - function duplicate string and allocate memory to it
 *@str: string to be duplicated
 * Return: pointer to new string or NULL if failed
 */
char *_strdup(const char *str)
{
size_t len = 0;
char *dup_str = NULL;
if (str == NULL)
return (NULL);
len = _strlen(str) + 1;
dup_str = (char *)malloc(len);
if (dup_str == NULL)
free(dup_str);
_strcpy(dup_str, str);
return (dup_str);
}
