#include "shell.h"
/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer to old block
 * @old_size: byte size of old block
 * @new_size: byte size of new block
 * Return: pointer to the new memory
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *p;
unsigned int i;
if (ptr == NULL)
{
p = malloc(new_size);
return (p);
}

if (new_size == 0)
{
free(ptr);
return ( NULL);
}

if (new_size == old_size)
return (ptr);

p = malloc(new_size);
if (p == NULL)
return (NULL);

if (new_size < old_size)
{
for (i = 0; i < new_size; i++)
{
p[i] = ((char *)ptr)[i];
}
}

else
{
for (i = 0; i < old_size; i++)
{
p[i] = ((char *)ptr)[i];
}
}

free(ptr);
return (p);
}
