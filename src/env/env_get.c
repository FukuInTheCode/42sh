/*
** EPITECH PROJECT, 2024
** env_get.c
** File description:
** env_get.c
*/

#include "my.h"

#include <string.h>

char *env_get(char **env, char const *var)
{
    if (!env || !var)
        return NULL;
    for (size_t i = 0; env[i]; i++) {
        if (!strncmp(env[i], var, strlen(var)) && env[i][strlen(var)] == '=')
            return env[i] + strlen(var) + 1;
    }
    return NULL;
}
