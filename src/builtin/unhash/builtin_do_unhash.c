/*
** EPITECH PROJECT, 2024
** builtin_do_unhash.c
** File description:
** builtin_do_unhash.c
*/

#include "my.h"

int builtin_do_unhash(command_t *command, shell_t *shell)
{
    if (command == NULL || shell == NULL)
        return 84;
    dprintf(2, "unhash: Not Implemented.\n");
    shell_set_code(shell, 1);
    return 0;
}
