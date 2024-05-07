/*
** EPITECH PROJECT, 2024
** shell_clean.c
** File description:
** shell_clean.c
*/

#include "my.h"

////////////////////////////////////////////////////////////
// int shell_clean(shell_t *shell)
//
// shell -> structure that contains all the data of the shell
//
// This function cleans the shell, file descriptors stdin stdout
// stderr and the commands.
//
// RETURN VALUE : int that is always 0
////////////////////////////////////////////////////////////
int shell_clean(shell_t *shell)
{
    shell_set_out(shell, SYS_OUT);
    shell_set_in(shell, SYS_IN);
    shell_set_err(shell, SYS_ERR);
    command_destroy(shell_get_cmds(shell));
    shell_set_cmds(shell, NULL);
    return 0;
}
