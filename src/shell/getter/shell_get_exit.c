/*
** EPITECH PROJECT, 2024
** shell_get_exit.c
** File description:
** shell_get_exit.c
*/

#include "my.h"

////////////////////////////////////////////////////////////
// bool shell_get_exit(shell_t *shell)
//
// shell -> structure that contains all the data of the shell
//
// This function returns the shell exit value.
//
// RETURN VALUE : boolean that returns the status of the
// shell exit.
////////////////////////////////////////////////////////////
bool shell_get_exit(shell_t *shell)
{
    return shell->do_exit;
}
