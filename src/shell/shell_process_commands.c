/*
** EPITECH PROJECT, 2024
** shell_process_commands.c
** File description:
** shell_process_commands.c
*/

#include "my.h"

#include <sys/wait.h>

////////////////////////////////////////////////////////////
// static int process_command(command_t *cmd, shell_t *shell,
// command_t **curr)
//
// shell -> structure of the shell
// cmd -> structure of the command
// curr -> structure of the current command
//
// This function processes one command.
//
// RETURN VALUE : int that is 84 if an error occurs, 0
// otherwise.
////////////////////////////////////////////////////////////
static int process_command(command_t *cmd, shell_t *shell, command_t **curr)
{
    if (command_get_type(cmd) == COMMAND)
        return shell_process_command(shell, cmd);
    if (command_get_type(cmd) == AND)
        return shell_process_and(shell, cmd, curr);
    if (command_get_type(cmd) == OR)
        return shell_process_or(shell, cmd, curr);
    if (command_get_type(cmd) == SUBSHELL_OPEN)
        return shell_process_subshell(shell, cmd, curr);
    return 0;
}

////////////////////////////////////////////////////////////
// int shell_process_commands(shell_t *shell)
//
// shell -> structure of the shell
//
// This function processes the commands.
//
// RETURN VALUE : int that is always 0.
////////////////////////////////////////////////////////////
int shell_process_commands(shell_t *shell)
{
    command_t *cmd = shell_get_cmds(shell);

    for (; cmd && !shell_get_exit(shell); cmd = command_get_next(cmd)) {
        process_command(cmd, shell, &cmd);
    }
    return 0;
}
