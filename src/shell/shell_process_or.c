/*
** EPITECH PROJECT, 2024
** shell_process_or.c
** File description:
** shell_process_or.c
*/

#include "my.h"

int shell_process_or(shell_t *shell, command_t *cmd, command_t **curr)
{
    command_t *prev = command_get_prev(cmd);
    command_t *next = command_get_next(cmd);

    if (!shell)
        return 84;
    if (!prev)
        return 0;
    if (command_get_status(prev) != 0)
        return 0;
    if (!next)
        return 0;
    command_set_status(next, !command_get_status(prev));
    *curr = next;
    return 0;
}
