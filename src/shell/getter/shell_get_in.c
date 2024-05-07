/*
** EPITECH PROJECT, 2024
** shell_get_in.c
** File description:
** shell_get_in.c
*/

#include "my.h"

////////////////////////////////////////////////////////////
// int shell_get_in(shell_t *shell)
//
// shell -> structure that contains all the data of the shell
//
// This function returns the shell input value.
//
// RETURN VALUE : int that represent the input of the shell
////////////////////////////////////////////////////////////
int shell_get_in(shell_t *shell)
{
    return shell->in;
}
