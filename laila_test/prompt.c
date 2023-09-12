#include "shell.h"

/**
 * prompt - print shell prompt
 */
void prompt(void)
{
char *cwd = malloc(PATH_MAX);

if (cwd == NULL)
{
perror("malloc");
exit(EXIT_FAILURE);
}
 
if (getcwd(cwd, PATH_MAX) == NULL)
{
perror("getcwd");
free(cwd);
exit(EXIT_FAILURE);
}
_print("$");
_print(cwd);
_print("$ ");
free(cwd);
}

