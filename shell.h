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
void shell_interactive_mode(void);
int execute_args(char **args, char *line);
int new_process(char **args);
int get_path(char **args);
char *build_path(char *token, char *value);
void shell_non_interactive_mode(void);

char *_strncpy(char *dest, const char *src, int n);
size_t _strlen(const char *s);
char *_strdup(const char *str);
char *_strcpy(char *dest, const char *src);
int _strncmp(const char *s1, const char *s2, size_t n);
int _strcmp(char *s1, char *s2);
char *_strchr(const char *s, int c);
int _atoi(const char *str);
char *_strcat(char *dest, char *src);

int _cd(char **args, char *line);
int cd_home(void);
int cd_dot(void);
int cd_to(char **args);
int _env(char **args, char *line);
int my_exit(char **args, char *line);
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

int add_node(Node **sptr, const char *value);
Node *build_path_list(void);
void printlist(Node *sptr);
void deletelist(Node **head);

#endif
