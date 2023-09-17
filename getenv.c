#include "shell.h"

/**
 * _getenv - function to find needed environment variable
 * @name : variable name
 * Return: pointer to the value of variable
 *         or NULL at fail
 */

char *_getenv(const char *name)
{
int i = 0, len = 0;
if (name == NULL || environ == NULL)
return (NULL);
len = _strlen(name);
while (environ[i])
{
if (_strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
{
return (&environ[i][len + 1]);
}
i++;
}
return (NULL);
}

/**
 * _setenv- Set or overwrite an environment variable
 * @name: the tokenized command
 * @value: input line
 **Return: 0 at success and -1 at fail
 */
int my_setenv(char **args, char __attribute__((unused)) *line,
int __attribute__((unused)) *flag)
{
int i = 0, j = 0, k = 0;
if (args == NULL || args[1] == NULL ||  args[2] == NULL)
{perror("setenv\n");
return (-1); }
for (i = 0; environ[i] != NULL; i++)
{
j = 0;
if (args[1][j] == environ[i][j])
{
while (args[1][j])
{
if (args[1][j] != environ[i][j])
break;
j++; }
if (args[1][j] == '\0')
{
k = 0;
while (args[2][k])
{
environ[i][j + 1 + k] = args[2][k];
k++; }
environ[i][j + 1 + k] = '\0';
return (0); }}}
if (environ[i] == NULL)
{
environ[i] = concat_all(args[1], "=", args[2]);
if (environ[i] == NULL)
return (-1);
environ[i + 1] = '\0';
return (0);
}
}
