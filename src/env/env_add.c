/*
** EPITECH PROJECT, 2024
** env_add.c
** File description:
** env_add.c
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

char **env_add(char **env, char const *var, char const *val)
{
    char **new_env = NULL;
    size_t len = 0;

    if (!env || !var)
        return env;
    len = my_len_word_array(env);
    new_env = calloc(len + 2, sizeof(char *));
    if (!new_env)
        return env;
    for (size_t i = 0; i < len; i++)
        new_env[i] = strdup(env[i]);
    new_env[len] = concat_val(var, val);
    return new_env;
}
