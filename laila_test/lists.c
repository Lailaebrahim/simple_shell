#include "shell.h"
/**
 *  add_node - function that add node at the start of list
 *             if no head node it creates it
 * @sptr: pointer to the head pointer of the list
 * @value: string to be added
 * Return: 1 at success and 0 when fail
 */

unsigned int add_node(Node **sptr, const char *value)
{
Node *currPtr = *sptr;
Node *newPtr = (Node *)malloc(sizeof(Node));
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
return (1);
}
else
{
while (currPtr->next != NULL)
currPtr = currPtr->next;
currPtr->next = newPtr;
return (1);
}
}
return (0);
}

/**
 *printlist - function that prints list
 *@sptr: pointer to the head node of list
 */
void printlist(Node *sptr)
{
Node *currptr = NULL;
Node *temp = NULL;
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
