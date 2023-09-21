#include "shell.h"

/**
 * _cd - changes the working dir of the current shell executon env
 * @args: target directory
 *@line: input line
 *@flag: flag to indicate changed environment
 * Return: 0 one success, -1 otherwise.
 */
int _cd(char **args, char  __attribute__((unused))*line
	, int __attribute__((unused))*flag)
{
if (args[1] == NULL)
{
return (-1);
}
else if (args[1] != NULL && args[2] != NULL)
{
return (-1);
}
else
{
if (chdir(args[1]) != 0)
{
return (-1);
}
}
return (0);
}
