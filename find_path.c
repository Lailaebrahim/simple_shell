#include "shell.h"

/**
 * get_path -  Search In $PATH For Excutable Command
 * @args: Parsed Input
 * Return: -1  Failure  0  Success.
 */
int get_path(char **args)
{
struct stat buff;
int i = 0;
char *cmd_path = NULL;
Node *temp = NULL;
Node *path_list = build_path_list();
temp = path_list;
if(temp == NULL)
{
for (i = 0; args[i] != NULL ; i++)
free(args[i]);
free(args);
return (-1); }   

while (temp != NULL)
{
cmd_path = build_path(args[0], temp->data);
if (stat(cmd_path, &buff) == 0)
{
free(args[0]);
args[0] = (char *)malloc(sizeof(char) * _strlen(cmd_path));

if (args[0] == NULL)
{free(cmd_path);
for (i = 1; args[i] != NULL ; i++)
free(args[i]);
free(args);
deletelist(&path_list);
return (-1);
}

for (i = 0 ; i < _strlen(cmd_path) ; i++)
args[0][i] = 0;

_strncpy(args[0], cmd_path, _strlen(cmd_path));
free(cmd_path);
deletelist(&path_list);
return (0);
}

free(cmd_path);
temp = temp->next;
}

for (i = 0 ; args[i] != NULL ; i++)
free(args[i]);
free(args);
deletelist(&path_list);
return (-1);
}

/**
 * build_path - Build Command
 * @token: Excutable Command
 * @value: Dirctory Conatining Command
 *
 * Return: Parsed Full Path Of Command Or NULL Case Failed
 */
char *build_path(char *token, char *value)
{

char *full_path = NULL;
size_t len = 0;
int i = 0;
len = _strlen(value) + _strlen(token) + 2;

full_path = (char *)malloc(sizeof(char) * len);

for(i = 0; i < len ; i++)
full_path[i] = 0;   

full_path = _strcat(full_path, value);
full_path = _strcat(full_path, "/");
full_path = _strcat(full_path, token);

return (full_path);

}
