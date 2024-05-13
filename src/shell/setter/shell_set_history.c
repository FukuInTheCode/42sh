/*
** EPITECH PROJECT, 2024
** shell_set_history.c
** File description:
** shell_set_history.c
*/

#include "my.h"

////////////////////////////////////////////////////////////
// int shell_set_history(shell_t *shell, history_t *history)
//
// shell -> structure that contains all the data of the shell
// history -> history of the shell
//
// This function sets the history of the shell.
//
// RETURN VALUE : int that is always 0
////////////////////////////////////////////////////////////
int shell_set_history(shell_t *shell, history_t *history)
{
    shell->history = history;
    return 0;
}
