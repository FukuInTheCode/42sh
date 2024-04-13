/*
** EPITECH PROJECT, 2024
** shell_set_code.c
** File description:
** shell_set_code.c
*/

#include "my.h"

#include <stdint.h>

int shell_set_code(shell_t *shell, uint8_t code)
{
    shell->exit_code = code;
    return 0;
}
