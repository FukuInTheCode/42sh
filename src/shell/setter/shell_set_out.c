/*
** EPITECH PROJECT, 2024
** shell_set_out.c
** File description:
** shell_set_out.c
*/

#include "shell.h"

int shell_set_out(shell_t *shell, int out)
{
    shell->out = out;
    return 0;
}
