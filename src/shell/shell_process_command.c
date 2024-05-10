/*
** EPITECH PROJECT, 2024
** shell_process_command.c
** File description:
** shell_process_command.c
*/

#include "my.h"

////////////////////////////////////////////////////////////
// int shell_process_command(shell_t *shell, command_t *cmd)
//
// shell -> structure of the shell
// cmd -> structure of the command
//
// This function processes one command in the shell.
//
// RETURN VALUE : int that is always 0
////////////////////////////////////////////////////////////
int shell_process_command(shell_t *shell, command_t *cmd)
{
    if (command_exec(cmd, (void *)shell))
        return 0;
    command_wait(cmd, (void *)shell);
    return 0;
}
