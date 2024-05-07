/*
** EPITECH PROJECT, 2024
** env_copy.c
** File description:
** env_copy.c
*/

#include "my.h"

#include <string.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////
// char **env_copy(char **env)
//
// env -> environment of the shell
//
// This function copies and returns the environment passed
// as parameter.
//
// RETURN VALUE : char ** that represent the copied env. NULL
// is returned is an error occurs
////////////////////////////////////////////////////////////
char **env_copy(char **env)
{
    char **new = NULL;

    if (!env)
        return NULL;
    new = calloc(my_len_word_array(env) + 1, sizeof(char *));
    if (!new)
        return NULL;
    for (size_t i = 0; env[i]; i++)
        new[i] = strdup(env[i]);
    return new;
}
