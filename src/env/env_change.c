/*
** EPITECH PROJECT, 2024
** env_remove.c
** File description:
** env_remove.c
*/

#include "my.h"

#include <string.h>
#include <stdlib.h>

static char *concat_val(char const *var, char const *val)
{
    size_t len = strlen(var);
    char *concated = NULL;

    if (val)
        len += strlen(val);
    concated = calloc(len + 2, sizeof(char));
    strcat(concated, var);
    strcat(concated, "=");
    if (val)
        strcat(concated, val);
    return concated;
}

char **env_change(char **env, char const *var, char const *val)
{
    char **new_env = NULL;
    size_t len = 0;

    if (!env || !var)
        return env;
    len = my_len_word_array(env);
    new_env = calloc(len + 1, sizeof(char *));
    if (!new_env)
        return env;
    for (size_t i = 0; i < len; i++) {
        if (!strncmp(var, env[i], strlen(var)) &&
            env[i][strlen(var)] == '=')
            new_env[i] = concat_val(var, val);
        else
            new_env[i] = strdup(env[i]);
    }
    return new_env;
}
