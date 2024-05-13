/*
** EPITECH PROJECT, 2024
** shell_process_and.c
** File description:
** shell_process_and.c
*/

#include "my.h"

////////////////////////////////////////////////////////////
// int shell_process_and(shell_t *shell, command_t *cmd,
// command_t **curr)
//
// shell -> structure of the shell
// cmd -> structure of the command
// curr -> structure of the current command
//
// This function processes the and.
//
// RETURN VALUE : int that is 84 if an error occurs, 0
// otherwise.
////////////////////////////////////////////////////////////
int shell_process_and(shell_t *shell, command_t *cmd, command_t **curr)
{
    command_t *prev = command_get_prev(cmd);
    command_t *next = command_get_next(cmd);

    if (!shell)
        return 84;
    if (!prev)
        return 0;
    if (command_get_status(prev) == 0)
        return 0;
    if (!next)
        return 0;
    command_set_status(next, command_get_status(prev));
    *curr = next;
    return 0;
}
