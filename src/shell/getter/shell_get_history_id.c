/*
** EPITECH PROJECT, 2024
** shell_get_in.c
** File description:
** shell_get_history.c
*/

#include "my.h"

////////////////////////////////////////////////////////////
// int shell_get_history_id(shell_t *shell)
//
// shell -> structure that contains all the data of the shell
//
// This function returns the shell history_id value.
//
// RETURN VALUE : int that represent the history_id of the shell
////////////////////////////////////////////////////////////
int shell_get_history_id(shell_t *shell)
{
    return shell->history_id;
}
