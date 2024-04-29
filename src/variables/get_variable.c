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
#include <stdlib.h>

char *remove_char(char const *str, char *to_remove)
{
    size_t len = strlen(str);
    int j = 0;
    char* result = (char*)malloc((len + 1) * sizeof(char));

    if (result == NULL)
        return NULL;
    for (size_t i = 0; i < len; i++) {
        if (strchr(to_remove, str[i]) == NULL) {
            result[j] = str[i];
            j++;
        }
    }
    result[j] = '\0';
    return result;
}

static int get_nbr_variable(char const *input) {
    int n = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '$' && (input[i + 1] != '\0' && input[i + 1] != ' '))
            n++;
    }
    return n;
}

void display_error_undefined_variable(char const *input)
{
    char *name_variable = remove_char(input, "$");

    dprintf(2, "%s: Undefined variables.\n", name_variable);
}

char *get_variable_env(char const *input, char **env)
{
    char *variable = remove_char(input, "$");
    char *name = NULL;

    if (input == NULL || env == NULL || variable == NULL)
        return NULL;
    name = env_get(env, variable);
    return name;
}

char *get_own_variable(char *input)
{
    if (input == NULL)
        return NULL;
    return NULL;
}

char *get_if_variable(char const *input, shell_t *shell)
{
    int nbr_variable = 0;
    char **env = NULL;
    char *new_input = strdup(input);

    env = shell_get_env(shell);
    nbr_variable = get_nbr_variable(input);
    if (nbr_variable == 0)
        return new_input;
    new_input = get_own_variable(new_input);
    if (new_input == NULL)
        new_input = get_variable_env(input, env);
    if (new_input == NULL) {
        display_error_undefined_variable(input);
        return NULL;
    }
    return new_input;
}
