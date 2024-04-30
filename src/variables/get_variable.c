/*
** EPITECH PROJECT, 2024
** get_variable.c
** File description:
** get_variable.c
*/

#include "my.h"
#include "shell.h"
#include "variables.h"
#include "env.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <unistd.h>

static char *display_var_error(char *var_name, shell_t *shell)
{
    dprintf(2, "%s: Undefined variable.\n", var_name);
    shell_set_code(shell, 1);
    free(var_name);
    return NULL;
}

static size_t get_var_len(char const *input)
{
    size_t len= 0;

    if (*input == '$')
        return 1;
    if (*input == '?')
        len++;
    for (; input[len] && (isalnum(input[len]) || input[len] == '_'); len++);
    return len;
}

static char *handle_special_vars(char const *var_name,
    shell_t *shell, char *value)
{
    if (*var_name == '$') {
        value = calloc(100, sizeof(char));
        sprintf(value, "%d", getpid());
    }
    if (*var_name == '?' || !strcmp("status", var_name)) {
        value = calloc(100, sizeof(char));
        sprintf(value, "%d", shell_get_code(shell));
    }
    if (!strcmp(var_name, "gid")) {
        value = calloc(100, sizeof(char));
        sprintf(value, "%d", getgid());
    }
    if (!strcmp(var_name, "uid")) {
        value = calloc(100, sizeof(char));
        sprintf(value, "%d", getuid());
    }
    return value;
}

static char *get_var_value(char const *var_name, shell_t *shell)
{
    char *value = handle_special_vars(var_name, shell, NULL);

    if (value)
        return value;
    if (!strcmp(var_name, "path")) {
        if (env_get(shell_get_env(shell), "PATH"))
            value = strdup(env_get(shell_get_env(shell), "PATH"));
        if (!value && getenv("PATH"))
            value = strdup(getenv("PATH"));
    }
    if (env_get(shell_get_env(shell), var_name))
        value = strdup(env_get(shell_get_env(shell), var_name));
    return value;
}

static char *variable_find(char *input, size_t *i, shell_t *shell)
{
    size_t var_len = get_var_len(input + *i + 1);
    char *var_name = NULL;
    char *new_input = NULL;
    char *var_val = NULL;

    if (!var_len || !shell)
        return input;
    var_name = strndup(input + *i + 1, var_len);
    var_val = get_var_value(var_name, shell);
    if (!var_val)
        return display_var_error(var_name, shell);
    new_input = calloc(*i + strlen(var_val) +
        strlen(input + *i + 1 + var_len), sizeof(char));
    snprintf(new_input, *i + 1, "%s", input);
    sprintf(new_input + *i, "%s%s", var_val, input + *i + 1 + var_len);
    free(var_name);
    free(var_val);
    free(input);
    return new_input;
}

char *variables_format(char const *input, shell_t *shell)
{
    char *new_input = strdup(input);

    if (!new_input || !shell)
        return NULL;
    for (size_t i = 0; new_input[i]; i++) {
        if (new_input[i] != '$')
            continue;
        new_input = variable_find(new_input, &i, shell);
        if (!new_input)
            return NULL;
    }
    return new_input;
}
