/*
** EPITECH PROJECT, 2024
** shell_set_code.c
** File description:
** shell_set_code.c
*/

#include "my.h"

#include <stdint.h>

////////////////////////////////////////////////////////////
// int shell_set_code(shell_t *shell, uint8_t code)
//
// shell -> structure that contains all the data of the shell
// code -> exit code of the shell
//
// This function sets the exit code of the shell.
//
// RETURN VALUE : int that is always 0
////////////////////////////////////////////////////////////
int shell_set_code(shell_t *shell, uint8_t code)
{
    shell->exit_code = code;
    return 0;
}
