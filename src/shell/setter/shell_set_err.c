/*
** EPITECH PROJECT, 2024
** shell_set_err.c
** File description:
** shell_set_err.c
*/

#include "my.h"

////////////////////////////////////////////////////////////
// int shell_set_err(shell_t *shell, int err)
//
// shell -> structure that contains all the data of the shell
// err -> file descriptor of the error output
//
// This function sets the error output of the shell.
//
// RETURN VALUE : int that is always 0
////////////////////////////////////////////////////////////
int shell_set_err(shell_t *shell, int err)
{
    shell->err = err;
    return 0;
}
