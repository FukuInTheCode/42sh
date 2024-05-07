/*
** EPITECH PROJECT, 2024
** shell_get_code.c
** File description:
** shell_get_code.c
*/

#include "my.h"

////////////////////////////////////////////////////////////
// uint8_t shell_get_code(shell_t *shell)
//
// shell -> structure that contains all the data of the shell
//
// This function returns the shell exit code value.
//
// RETURN VALUE : uint8_t that represent the exit code of the shell
////////////////////////////////////////////////////////////
uint8_t shell_get_code(shell_t *shell)
{
    return shell->exit_code;
}
