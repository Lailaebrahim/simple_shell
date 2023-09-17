#include "shell.h"
/**
 * _getline - function to read command
 * @lineptr : Buffer to store read command
 *@n: Size of buffer
 *@stream:Stream from which function will read commamd
 *Return:Number of characters read at success
 *         -1 at fail and 0 at EOF
 */
ssize_t _getline(char **lineptr, size_t *n, int stream)
{
char c = 0;
int ret = 0;
size_t i = 0;
if (lineptr == NULL || n == NULL || stream == -1)
return (-1);
if (*lineptr == NULL || *n == 0)
{
*n = BUFFER_SIZE;
*lineptr = (char *)malloc(*n);
if (*lineptr == NULL)
return (-1);
}
for (i = 0 ; ; i++)
{
if (i > *n)
{
*n *= 2;
*lineptr = (char *)_realloc(lineptr, (*n) / 2, *n);
if (*lineptr == NULL)
return (-1);
}
ret = read(stream, &c, 1);
if (ret == 0)
{
if (i == 0)
{
free(*lineptr);
*lineptr = NULL;
perror("EOF\n");
return (0); }
else
{
(*lineptr)[i] = '\0';
return (i); }}
else if (ret == -1 || ret != 1)
return (-1);
(*lineptr)[i] = c;
if (c == '\n')
{
(*lineptr)[i] = '\0';
return (i); }}}
