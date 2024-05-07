/*
** EPITECH PROJECT, 2024
** shell_set_in.c
** File description:
** shell_set_in.c
*/

#include "my.h"

////////////////////////////////////////////////////////////
// int shell_set_in(shell_t *shell, int in)
//
// shell -> structure that contains all the data of the shell
// in -> file descriptor of the input
//
// This function sets the input of the shell.
//
// RETURN VALUE : int that is always 0
////////////////////////////////////////////////////////////
int shell_set_in(shell_t *shell, int in)
{
    shell->in = in;
    return 0;
}
