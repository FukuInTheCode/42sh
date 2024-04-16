/*
** EPITECH PROJECT, 2024
** builtin_do_colon.c
** File description:
** builtin_do_colon.c
*/

#include "my.h"

int builtin_do_colon(command_t *command, shell_t *shell)
{
    if (command == NULL || shell == NULL)
        return 84;
    shell_set_code(shell, 0);
    return 0;
}
