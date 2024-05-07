/*
** EPITECH PROJECT, 2024
** shell_set_cmds.c
** File description:
** shell_set_cmds.c
*/

#include "my.h"

////////////////////////////////////////////////////////////
// int shell_set_cmds(shell_t *shell, command_t *cmds)
//
// shell -> structure that contains all the data of the shell
// cmds -> current command
//
// This function sets the current command of the shell.
//
// RETURN VALUE : int that is always 0
////////////////////////////////////////////////////////////
int shell_set_cmds(shell_t *shell, command_t *cmds)
{
    shell->cmds = cmds;
    return 0;
}
