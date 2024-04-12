/*
** EPITECH PROJECT, 2024
** shell_set_err.c
** File description:
** shell_set_err.c
*/

#include "my.h"

int shell_set_err(shell_t *shell, int err)
{
    shell->err = err;
    return 0;
}
