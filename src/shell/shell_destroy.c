/*
** EPITECH PROJECT, 2024
** shell_destroy.c
** File description:
** shell_destroy.c
*/

#include "my.h"
#include "builtins.h"
#include "history.h"
#include <env.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////
// int shell_destroy(shell_t *shell)
//
// shell -> structure that contains all the data of the shell
//
// This function frees all the shell values.
//
// RETURN VALUE : int that is always 0
////////////////////////////////////////////////////////////
int shell_destroy(shell_t *shell)
{
    env_destroy(shell_get_env(shell));
    command_destroy(shell_get_cmds(shell));
    set_destroy(shell);
    remove_history(shell);
    if (shell_get_out(shell) != SYS_OUT)
        close(shell_get_out(shell));
    if (shell_get_in(shell) != SYS_IN)
        close(shell_get_in(shell));
    if (shell_get_err(shell) != SYS_ERR)
        close(shell_get_err(shell));
    free(shell);
    return 0;
}
