/*
** EPITECH PROJECT, 2024
** builtin_do_bg.c
** File description:
** builtin_do_bg.c
*/

#include "my.h"

int builtin_do_bg(command_t *command, shell_t *shell)
{
    if (command == NULL || shell == NULL)
        return 84;
    dprintf(2, "bg: Not Implemented.\n");
    shell_set_code(shell, 1);
    return 0;
}
