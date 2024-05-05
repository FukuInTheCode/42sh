/*
** EPITECH PROJECT, 2024
** env_destroy.c
** File description:
** env_destroy.c
*/

#include "my.h"

#include <stdlib.h>

////////////////////////////////////////////////////////////
// int env_destroy(char **env)
//
// env -> environment of the shell
//
// This function destroys and free the environment passed as
// parameter.
//
// RETURN VALUE : int that is always 0
////////////////////////////////////////////////////////////
int env_destroy(char **env)
{
    if (!env)
        return 0;
    for (size_t i = 0; env[i]; i++)
        free(env[i]);
    free(env);
    return 0;
}
