#include "shell.h"

int main(int __attribute__((unused)) argc, char *argv, char *env[])
{
if (isatty(STDIN_FILENO) == 1)
{
shell_interactive_mode();     
}
else
{
shell_non_interactive_mode();
}
return (0);
}

void shell_interactive_mode(void)
{
char *line;
char **args;
int status = -1, num_tokens;
ssize_t n = 0, rd = 0;
char *delim = " ";
while(1)
{
prompt();
rd = _getline(&line, &n, STDIN_FILENO);
if(rd == 0)
exit(EXIT_SUCCESS);
if(rd == -1)
{
free(line);
perror("error while reading the line from stdin");
exit(EXIT_FAILURE);
}
args = _strtok(line, delim, &num_tokens);
if (args == NULL)
exit(EXIT_FAILURE);
status = execute_args(args);
if (status != -1)
{
perror("failed to execute");
}
}
}

void shell_non_interactive_mode(void)
{
_print("_non_interactive_mode");
}
