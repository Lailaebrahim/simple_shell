#include "shell.h"
/**
 * build_path_list - function that create a single linked list where the value
 *                   of each node is a directory
 * Return: pointer to the list of directories
 */
Node *build_path_list(void)
{
Node *temp = NULL;
Node *list = NULL;
char *path = _getenv("PATH");
 int num_tokens = 0, i = 0, j = 0;
char **tokens = NULL;
if (path == NULL)
{
perror("Failed to get PATH variable");
exit(EXIT_FAILURE);
}
tokens = _strtok(path, ":", &num_tokens);
if (tokens == NULL)
return (NULL);
for (i = 0 ; i < num_tokens && tokens[i] != NULL ; i++)
{
if (add_node(&list, tokens[i]) == -1)
{
perror("Failed to insert directory into the list");
while (list != NULL)
{
temp = list;
list = list->next;
free(temp->data);
free(temp);
}
for (j = 0; tokens[j] != NULL ; j++)
free(tokens[j]);
free(tokens);
exit(EXIT_FAILURE);
}
}
for (j = 0; tokens[j] != NULL ; j++)
free(tokens[j]);
free(tokens);
return (list);
}
