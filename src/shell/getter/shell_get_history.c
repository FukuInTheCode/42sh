/*
** EPITECH PROJECT, 2024
** shell_get_in.c
** File description:
** shell_get_history.c
*/

#include "my.h"

////////////////////////////////////////////////////////////
// int shell_get_history(shell_t *shell)
//
// shell -> structure that contains all the data of the shell
//
// This function returns the shell history value.
//
// RETURN VALUE : history_t that represent the history of the shell
////////////////////////////////////////////////////////////
history_t *shell_get_history(shell_t *shell)
{
    return shell->history;
}
