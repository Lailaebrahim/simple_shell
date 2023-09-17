#include "shell.h"

/**
 * my_exit - exit of the program with the status
 * @args: tokenized command line
 *@line: input line
 * Return: 0 at sucess, or status in the arguments
 */
int my_exit(char **args, char *line, int *flag)
{
int i = 0, n = 0;
if (args[1] != NULL)
{
n = _atoi(args[1]);
if (n <= -1)
n = 2;
}
for(i = 0; args[i] != NULL; i++)
{free(args[i]);
args[i] = NULL; }
free(args);
args = NULL;
free(line);
line = NULL;
if (*flag != 0)
{
while (environ[i] != NULL)
i++;
while (*flag != 0)
{
free(environ[i - *flag]);
--(*flag);
}
}

exit(n);
}

