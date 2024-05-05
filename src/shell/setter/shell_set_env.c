/*
** EPITECH PROJECT, 2024
** shell_set_env.c
** File description:
** shell_set_env.c
*/

#include "my.h"
#include "env.h"

////////////////////////////////////////////////////////////
// int shell_set_env(shell_t *shell, char **env)
//
// shell -> structure that contains all the data of the shell
// env -> environment of the shell
//
// This function sets the environment of the shell.
//
// RETURN VALUE : int that is always 0
////////////////////////////////////////////////////////////
int shell_set_env(shell_t *shell, char **env)
{
    env_destroy(shell->env);
    shell->env = env;
    return 0;
}
