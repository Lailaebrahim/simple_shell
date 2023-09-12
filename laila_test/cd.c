#include "shell.h"

/**
 * _cd - changes the working dir of the current shell executon env
 * @args: target directory
 *
 * Return: 1 one success, -1 otherwise.
 */
int _cd(char **args)
{
if (args[1] == NULL)
{
perror("expected argument to \"cd\"\n");
}
else
{
if (chdir(args[1]) != 0)
{
perror("error in _cd.c: changing dir\n");
}
}
return (-1);
}
