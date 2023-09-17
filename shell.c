#include "shell.h"
/**
 * main - Entry point
 * @argc: number of arguments
 * @argv: arguments passed
 * Return: 0 at succes
 */

int main(int __attribute__((unused)) argc, char __attribute__((unused)) **argv)
{
if (isatty(STDIN_FILENO) == 1)
{
signal(SIGINT, signal_handler);
shell_interactive_mode();
}
else
{
shell_non_interactive_mode();
}
return (0);
}
/**
 *shell_interactive_mode - running shell ininteractive mode
 */
void shell_interactive_mode(void)
{
char *line = NULL;
char **args = NULL;
int status = 0, num_tokens = 0;
size_t n = 0;
ssize_t rd = 0;
char *delim = " ";
while (1)
{
prompt();
rd = _getline(&line, &n, STDIN_FILENO);
fflush(stdin);
if (rd == 0)
{
exit(EXIT_SUCCESS); }

if (rd == -1)
{if (line != NULL)
free(line);
perror("error while reading the line from stdin\n");
exit(EXIT_FAILURE); }

args = _strtok(line, delim, &num_tokens);
if (args == NULL)
{
if (line != NULL)
free(line);
exit(EXIT_FAILURE); }

status = execute_args(args, line);
if (status == -1)
perror("failed to execute\n");

}
/*end of while */
}
/**
 *shell_non_interactive_mode - running shell in non interactive mode
 */
void shell_non_interactive_mode(void)
{
char *line = NULL;
char **args = NULL;
int status = 0, num_tokens = 0;
size_t n = 0;
ssize_t rd = 0;
char *delim = " ";
while (1)
{
rd = _getline(&line, &n, STDIN_FILENO);
if (rd == 0)
{
if (line != NULL)
free(line);
exit(EXIT_SUCCESS); }

if (rd == -1)
{if (line != NULL)
free(line);
perror("error while reading the line from file\n");
exit(EXIT_FAILURE); }

args = _strtok(line, delim, &num_tokens);
if (args == NULL)
{
if (line != NULL)
free(line);
exit(EXIT_FAILURE); }

status = execute_args(args, line);
if (status == -1)
perror("failed to execute\n");

}
}


/**
 * signal_handler - checks if Ctrl C is pressed
 * @signal_num: int
 */
void signal_handler(int signal_num)
{
if (signal_num == SIGINT)
{
_print("\n");
prompt();
}
}
