/*
** EPITECH PROJECT, 2024
** shell_set_exit.c
** File description:
** shell_set_exit.c
*/

#include "my.h"

////////////////////////////////////////////////////////////
// int shell_set_exit(shell_t *shell, bool do_exit)
//
// shell -> structure that contains all the data of the shell
// do_exit -> status of the exit
//
// This function sets the exit status of the shell.
//
// RETURN VALUE : int that is always 0
////////////////////////////////////////////////////////////
int shell_set_exit(shell_t *shell, bool do_exit)
{
    shell->do_exit = do_exit;
    return 0;
}
