/*
** EPITECH PROJECT, 2024
** shell_get_out.c
** File description:
** shell_get_out.c
*/

#include "my.h"

////////////////////////////////////////////////////////////
// int shell_get_out(shell_t *shell)
//
// shell -> structure that contains all the data of the shell
//
// This function returns the shell output value.
//
// RETURN VALUE : int that represent the output of the shell
////////////////////////////////////////////////////////////
int shell_get_out(shell_t *shell)
{
    return shell->out;
}
