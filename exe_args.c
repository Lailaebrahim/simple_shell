#include "shell.h"

/**
 * execute_args - check if command is a builtin or an executable
 * @args: tokenized command
 *@line: input line
 * Return: 0 on sucess, -1 otherwise
 */
int execute_args(char **args, char *line)
{
unsigned long int i = 0;
int ret = 0;
char *builtin_func_list[3] = {"cd", "env", "exit"};
int (*builtin_func[3])(char **, char *) = {&_cd, &_env, &my_exit};
if (args == NULL || args[0] == NULL)
return (-1);

for (i = 0; i < 3; i++)
{
if (_strcmp(args[0], builtin_func_list[i]) == 0)
{
ret = (*builtin_func[i])(args, line);
for (i = 0; args[i] != NULL; i++)
free(args[i]);
free(args);
free(line);
line = NULL;
return (ret);
}
}

ret = new_process(args);
if (ret == 0)
{
for (i = 0; args[i] != NULL; i++)
free(args[i]);
free(args);
}
free(line);
line = NULL;
return (ret);
}
/**
 *new_process - function to execute executable command
 *@args: pointer to tokenized comamnd
 *Return: 0 at success , -1 at fail
 */

int new_process(char **args)
{
pid_t pid = 0;
int status = 0, i = 0;
int ret = 0;
if (_strncmp(args[0], "./", 2) != 0 && _strncmp(args[0], "/", 1) != 0)
{ret = get_path(args);
if (ret == -1)
{perror("inside new process failed to find path\n");
return (-1); }
}

pid = fork();
if (pid ==  0)
{
/* child process */
if (execve(args[0], args, environ) == -1)
{
for (i = 0 ; args[i] != NULL ; i++)
free(args[i]);
free(args);
perror("Failed to execute in child process");
return (-1); }}

else if (pid < 0)
{
perror("error in new_process: forking");
for (i = 0 ; args[i] != NULL ; i++)
free(args[i]);
free(args);
exit(EXIT_FAILURE); }

else
{
do {
waitpid(pid, &status, WUNTRACED);
} while (!WIFEXITED(status) && !WIFSIGNALED(status));

}
return (0);
}
