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
 * my_setenv- Set or overwrite an environment variable
 * @args: the tokenized command
 * @line: input line
 *@flag: to indicate if a new environment variable is set
 *Return: 0 at success and -1 at fail
 */
int my_setenv(char **args, char __attribute__((unused))*line
	      , int __attribute__((unused))*flag)
{
int i = 0, j = 0, k = 0;
if (args == NULL || args[1] == NULL ||  args[2] == NULL)
{
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
return (0);
}
}
}
if (environ[i] == NULL)
{
environ[i] = concat_all(args[1], "=", args[2]);
if (environ[i] == NULL)
return (-1);
environ[i + 1] = '\0';
return (0);
}
return (-1);
}



/**
 * my_unsetenv- unset an environment variable
 * @args: the tokenized command
 * @line: input line
 *@flag: to indicate if a new environment variable is set
 *Return: 0 at success and -1 at fail
 */
int my_unsetenv(char **args, char __attribute__((unused))*line
	      , int *flag)
{
int i, j;
if (args[1] == NULL  || args[2] != NULL)
{
perror(_getenv("_"));
return (-1); }
for (i = 0; environ[i]; i++)
{
j = 0;
if (args[1][j] == environ[i][j])
{
while (args[1][j])
{
if (args[1][j] != environ[i][j])
break;
j++;
}
if (args[1][j] == '\0')
{
free(environ[i]);
environ[i] = environ[i + 1];
while (environ[i])
{
environ[i] = environ[i + 1];
i++;
}
if (*flag > 0)
(*flag)--;
return (0);
}
}
}

return (-1);
}
