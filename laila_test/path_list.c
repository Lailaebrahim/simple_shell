#include "shell.h"
/**
 * build_path_list - function that create a single linked list where the value
 *                   of each node is a directory
 * Return: pointer to the list of directories
 */
Node *build_path_list(void)
{
Node *temp = NULL;
Node *head = NULL;
Node *list = NULL;
char *path = _getenv("PATH");
char *token;
if (path == NULL)
{
perror("Failed to get PATH variable");
exit(EXIT_FAILURE);
}
token = strtok(path, ":");
while (token != NULL)
{

if (!add_node(&list, token))
{
perror("Failed to insert directory into the list");
while (list != NULL)
{
temp = list;
list = list->next;
free(temp->data);
free(temp);
}
exit(EXIT_FAILURE);
}

token = strtok(NULL, ":");
}

return (list);
}
