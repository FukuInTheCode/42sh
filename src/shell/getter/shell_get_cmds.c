/*
** EPITECH PROJECT, 2024
** shell_get_cmds.c
** File description:
** shell_get_cmds.c
*/

#include "my.h"

////////////////////////////////////////////////////////////
// command_t *shell_get_cmds(shell_t *shell)
//
// shell -> structure that contains all the data of the shell
//
// This function returns the shell command value.
//
// RETURN VALUE : command_t * that returns the value of the
// shell command value.
////////////////////////////////////////////////////////////
command_t *shell_get_cmds(shell_t *shell)
{
    return shell->cmds;
}
