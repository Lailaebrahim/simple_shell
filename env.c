#include "shell.h"

/**
 * _env - fuction that print the current environment variables
 *@args : pointer to tokenized string
 *@line: input line
 *Return: 0 at success and -1 at fail
 */

int _env(char __attribute__((unused)) **args, char  __attribute__ ((unused)) *line,
int __attribute__((unused)) *flag)
{

int i = 0, ret = 0;
while (environ[i])
{
ret = write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
if (ret == -1)
{perror("write failed\n");
return (-1); }
ret = write(STDOUT_FILENO, "\n", 1);
if (ret == -1)
{perror("write failed\n");
return (-1); }
i++;
}
return (0);
}
