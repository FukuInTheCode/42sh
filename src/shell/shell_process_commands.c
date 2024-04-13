/*
** EPITECH PROJECT, 2024
** shell_process_commands.c
** File description:
** shell_process_commands.c
*/

#include "my.h"

#include <sys/wait.h>

static int process_command(command_t *cmd, shell_t *shell)
{
    if (cmd->type != COMMAND)
        return 0;
    if (command_exec(cmd, (void *)shell))
        return 0;
    command_wait(cmd, (void *)shell);
    return 0;
}

int shell_process_commands(shell_t *shell)
{
    command_t *cmd = shell_get_cmds(shell);

    for (; cmd && !shell_get_exit(shell); cmd = command_get_next(cmd)) {
        process_command(cmd, shell);
    }
    return 0;
}
