/*
** EPITECH PROJECT, 2024
** shell_get_env.c
** File description:
** shell_get_env.c
*/

#include "my.h"

////////////////////////////////////////////////////////////
// char **shell_get_env(shell_t *shell)
//
// shell -> structure that contains all the data of the shell
//
// This function returns the environment of the shell.
//
// RETURN VALUE : char ** that is the environment of the shell
////////////////////////////////////////////////////////////
char **shell_get_env(shell_t *shell)
{
    return shell->env;
}
