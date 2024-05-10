/*
** EPITECH PROJECT, 2024
** shell_set_out.c
** File description:
** shell_set_out.c
*/

#include "shell.h"

////////////////////////////////////////////////////////////
// int shell_set_out(shell_t *shell, int out)
//
// shell -> structure that contains all the data of the shell
// out -> file descriptor of the output
//
// This function sets the output of the shell.
//
// RETURN VALUE : int that is always 0
////////////////////////////////////////////////////////////
int shell_set_out(shell_t *shell, int out)
{
    shell->out = out;
    return 0;
}
