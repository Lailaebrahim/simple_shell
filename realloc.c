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
char *p = NULL;
unsigned int i = 0;
if (ptr == NULL)
return (malloc(new_size));

if (new_size == 0)
return (NULL);

if (new_size == old_size)
return (ptr);

p = malloc(new_size);
if (p == NULL)
return (NULL);

fill_arr_with_zero(p, new_size);

if (new_size < old_size)
{
for (i = 0; i < new_size; i++)
p[i] = ((char *)ptr)[i];
}

else
{
for (i = 0; i < old_size; i++)
p[i] = ((char *)ptr)[i];
}

free(ptr);

return (p);
}
