#include "shell.h"
/**
 *  add_node - function that add node at the start of list
 *             if no head node it creates it
 * @sptr: pointer to the head pointer of the list
 * @value: string to be added
 * Return: 0 at success and -1 when fail
 */

int add_node(Node **sptr, const char *value)
{
Node *currPtr = *sptr;
Node *newPtr = NULL;
newPtr = (Node *)malloc(sizeof(Node));
if (newPtr == NULL)
{
perror("Memory allocation failed");
exit(EXIT_FAILURE);
}
else
{
newPtr->data = _strdup(value);
if (newPtr->data == NULL)
{
perror("String duplication failed");
exit(EXIT_FAILURE);
}
newPtr->next = NULL;

if (*sptr == NULL)
{
*sptr = newPtr;
return (0);
}
else
{
while (currPtr->next != NULL)
currPtr = currPtr->next;
currPtr->next = newPtr;
return (0);
}
}
return (-1);
}

/**
 *printlist - function that prints list
 *@sptr: pointer to the head node of list
 */
void printlist(Node *sptr)
{
Node *currptr = NULL;
if (sptr == NULL)
{
perror("LIST IS EMPTY");
exit(EXIT_FAILURE);
}
else
{
currptr = (sptr);
while (currptr != NULL)
{
_print(currptr->data);
_print("\n");
currptr = currptr->next;
}
}
}
/**
 * deletelist - function that delete list and free allocated mem
 *@head: pointer to head pointer of list
 */
void deletelist(Node **head)
{
Node *current = *head;
Node *nextNode = *head;

while (current != NULL)
{
nextNode = current->next;
free(current->data);
free(current);
current = nextNode;
}

*head = NULL;
}
