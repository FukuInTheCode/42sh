/*
** EPITECH PROJECT, 2024
** builtin_do_if.c
** File description:
** builtin_do_if.c
*/

#include "my.h"

int builtin_do_if(command_t *command, shell_t *shell)
{
    if (command == NULL || shell == NULL)
        return 84;
    dprintf(2, "if: Not Implemented.\n");
    shell_set_code(shell, 1);
    return 0;
}
