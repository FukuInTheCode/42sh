/*
** EPITECH PROJECT, 2024
** shell_get_code.c
** File description:
** shell_get_code.c
*/

#include "my.h"

uint8_t shell_get_code(shell_t *shell)
{
    return shell->exit_code;
}
