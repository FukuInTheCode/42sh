/*
** EPITECH PROJECT, 2024
** env_remove.c
** File description:
** env_remove.c
*/

#include "my.h"

#include <string.h>
#include <stdlib.h>

char **env_remove(char **env, char const *var)
{
    char **new_env = NULL;
    size_t len = 0;
    size_t j = 0;

    if (!env || !var)
        return env;
    len = my_len_word_array(env);
    new_env = calloc(len, sizeof(char *));
    if (!new_env)
        return env;
    for (size_t i = 0; i < len; i++) {
        if (!strncmp(var, env[i], strlen(var)) &&
            env[i][strlen(var)] == '=')
            continue;
        new_env[j] = strdup(env[i]);
        j++;
    }
    return new_env;
}
