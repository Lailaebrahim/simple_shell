#ifndef _SHELL_H_
#define _SHELL_H_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>
#include <limits.h>


#define BUFFER_SIZE 1024

#define _print(c) (write(STDOUT_FILENO, c, _strlen(c)))

extern char **environ;

void prompt(void);
char *_getenv(const char *name);
int addEnvironmentEntry(const char *name, const char *value);
int _setenv(const char *name, const char *value, int overwrite);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
ssize_t _getline(char **lineptr, size_t *n, int stream);
char **_strtok(const char *lineptr, const char *delim, int *num_tokens);
char **__strtok(char *str, const char *delimiters);
void shell_interactive_mode(void);
int execute_args(char **args);
int new_process(char **args);
void shell_non_interactive_mode(void);

char *_strncpy(char *dest, const char *src, int n);
size_t _strlen(const char *s);
char *_strdup(const char *str);
char *_strcpy(char *dest, const char *src);
int _strncmp(const char *s1, const char *s2, size_t n);
int _strcmp(char *s1, char *s2);
char *_strchr(const char *s, int c);

int _cd(char **args);

/**
 * struct data - struct for the program's data
 * @program_name: the name of the executable file
 * @command_line: pointer to the input read by _getline
 * @command_name: pointer to the first command typed by the user
 * @exec_counter: number of excecuted comands
 * @fd: file descriptor of input stream
 * @tokens: pointer to array of tokenized command
 * @env: copy of the environ global variable
 * @alias_list: array of pointers with aliases.
 */
typedef struct data
{
char *program_name;
char *command_line;
char *command_name;
int exec_counter;
int fd;
char **tokens;
char **env;
char **alias_list;
} program_data;

/**
 * struct Node - singly linked list
 * @data: string dynamically allocated
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct Node
{
char *data;
struct Node *next;
} Node;

unsigned int add_node(Node **sptr, const char *value);
Node *build_path_list(void);
void printlist(Node *sptr);

#endif
