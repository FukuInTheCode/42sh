/*
** EPITECH PROJECT, 2024
** builtin_do_shift.c
** File description:
** builtin_do_shift.c
*/

#include "my.h"

int builtin_do_shift(command_t *command, shell_t *shell)
{
    if (command == NULL || shell == NULL)
        return 84;
    dprintf(2, "shift: Not Implemented.\n");
    shell_set_code(shell, 1);
    return 0;
}
