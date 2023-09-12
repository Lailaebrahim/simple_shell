#include "shell.h"
/**
 * isDelimiter - helper function to detect a delimiter is encountered
 * @c : char to check
 * @delimiters: delimiter to be detected
 * Return: 1 if delimiter is encountered
 *         -1 if not
 */
int isDelimiter(char c, const char *delimiters)
{
while (*delimiters)
{
if (*delimiters == c)
{
return (1);
}
delimiters++;
}
return (0);
}
/**
 * _strtok - function that take a string to toknize it
 * @str: string to be tokenized
 * @delimiters: delimiter
 * @num_tokens: to store number of tomens
 * Return: an array of pointers to tokens
 */
char **_strtok(const char *str, const char *delimiters, int *num_tokens)
{const char *token_start = str, *token_end;
size_t token_length = 0;
int i = 0, token_index = 0;
char **tokens;
if (str == NULL || delimiters == NULL)
return (NULL);
*num_tokens = 0;
while (*token_start)
{
while (*token_start && isDelimiter(*token_start, delimiters))
token_start++;
if (*token_start)
(*num_tokens)++;
while (*token_start && !isDelimiter(*token_start, delimiters))
token_start++; }
if (*num_tokens == 0)
return (NULL);
tokens = (char **)malloc((*num_tokens + 1) * sizeof(char *));
if (tokens == NULL)
return (NULL);
token_start = str;
while (*token_start)
{
while (*token_start && isDelimiter(*token_start, delimiters))
token_start++;
if (*token_start)
{token_end = token_start;
while (*token_end && !isDelimiter(*token_end, delimiters))
token_end++;
token_length = token_end - token_start;
tokens[token_index] = (char *)malloc(token_length + 1);
if (tokens[token_index] == NULL)
{
for (int i = 0; i < token_index; i++)
free(tokens[i]);
free(tokens);
return (NULL); }
_strncpy(tokens[token_index++], token_start, token_length);
token_start = token_end; }}
tokens[*num_tokens] = NULL;
return (tokens); }
