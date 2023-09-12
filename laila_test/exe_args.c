#include "shell.h"

/**
 * execute_args - check if command is a builtin or an executable
 * @args: tokenized command
 *
 * Return: 1 on sucess, 0 otherwise
 */
int execute_args(char **args)
{
unsigned long int i = 0;
char *builtin_func_list[] = {"cd","env","help","exit"};
int (*builtin_func[])(char **) =
{
&_cd,
};
if (args[0] == NULL)
return (-1);
for (; i < sizeof(builtin_func_list) / sizeof(char *); i++)
{
if (_strcmp(args[0], builtin_func_list[i]) == 0)
return ((*builtin_func[i])(args));
}
return (new_process(args));
}
int new_process(char **args)
{
return (1);
}
