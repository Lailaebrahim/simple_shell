#include "shell.h"

/**
 * _getenv - function to find needed environment variable
 * @name : variable name
 * Return: pointer to the value of variable
 *         or NULL at fail
 */

char *_getenv(const char *name)
{
int i = 0, len = 0;
if (name == NULL || environ == NULL)
return (NULL);
len = _strlen(name);
while (environ[i])
{
if (_strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
{
return (&environ[i][len + 1]);
}
i++;
}
return (NULL);
}

/**
 *addEnvironmentEntry - Add a new environment variable entry
 * @name: The name of the environment variable
 * @value: The value of the environment variable
 *Return: 0 at success and -1 at fail
 */
int addEnvironmentEntry(const char *name, const char *value)
{
char *new_env = NULL;
char **new_environ = NULL;
int env_count = 0, i = 0;
size_t new_env_len = _strlen(name) + _strlen(value) + 2;
new_env = (char *)malloc(new_env_len);
if (new_env == NULL)
{errno = ENOMEM;
return (-1); }
_strncpy(new_env, name, _strlen(name));
_strncpy(new_env + _strlen(name), "=", 1);
_strncpy(new_env + _strlen(name) + 1, value, _strlen(value));
while (environ[env_count] != NULL)
env_count++;
new_environ = (char **)malloc((env_count + 2) * sizeof(char *));
if (new_environ == NULL)
{free(new_env);
errno = ENOMEM;
return (-1); }
for (i = 0; i < env_count; i++)
new_environ[i] = environ[i];
new_environ[env_count] = new_env;
new_environ[env_count + 1] = NULL;
environ = new_environ;
return (0);
}

/**
 * _setenv- Set or overwrite an environment variable
 * @name: The name of the environment variable
 * @value: The value of the environment variable
 * @overwrite: Flag to indicate whether to overwrite an existing variable
 **Return: 0 at success and -1 at fail
 */
int _setenv(const char *name, const char *value, int overwrite)
{
char *existing_value = NULL, *equal_sign = NULL;
int i;
size_t name_len;
if (name == NULL || value == NULL)
{errno = EINVAL;
return (-1); }
existing_value = _getenv(name);
if (existing_value != NULL)
{
if (overwrite == 0)
return (0);
else
{
for (i = 0; environ[i] != NULL; i++)
{equal_sign = _strchr(environ[i], '=');
if (equal_sign != NULL)
{name_len = equal_sign - environ[i];
if (_strncmp(environ[i], name, name_len) == 0 && name_len == _strlen(name))
{free(existing_value);
environ[i] = (char *)malloc(_strlen(name) + _strlen(value) + 2);
if (environ[i] == NULL)
{errno = ENOMEM;
return (-1); }
_strncpy(environ[i], name, _strlen(name));
_strncpy(environ[i] + _strlen(name), "=", 1);
_strncpy(environ[i] + _strlen(name) + 1, value, _strlen(value));
return (0); }}}}}
return (addEnvironmentEntry(name, value));
}
