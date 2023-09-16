#include "shell.h"

/**
 * my_exit - exit of the program with the status
 * @args: tokenized command line
 *@line: input line
 * Return: 0 at sucess, or status in the arguments
 */
int my_exit(char **args, char *line)
{
int i, n;
if (args[1] != NULL)
{
n = _atoi(args[1]);
if (n <= -1)
n = 2;
for (i = 0; args[i] != NULL; i++)
free(args[i]);
free(args);
free(line);
exit(n);
}

for (i = 0; args[i] != NULL; i++)
free(args[i]);
free(args);
free(line);
exit(0);
}
