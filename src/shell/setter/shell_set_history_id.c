/*
** EPITECH PROJECT, 2024
** shell_set_history_id.c
** File description:
** shell_set_history_id.c
*/

#include "my.h"

////////////////////////////////////////////////////////////
// int shell_set_history_id(shell_t *shell, int history_id)
//
// shell -> structure that contains all the data of the shell
// history_id -> id of the history on the shell
//
// This function sets the history_id of the shell.
//
// RETURN VALUE : int that is always 0
////////////////////////////////////////////////////////////
int shell_set_history_id(shell_t *shell, int history_id)
{
    shell->history_id = history_id;
    return 0;
}
