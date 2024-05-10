/*
** EPITECH PROJECT, 2024
** builtin_do_suspend.c
** File description:
** builtin_do_suspend.c
*/

#include "my.h"

int builtin_do_suspend(command_t *command, shell_t *shell)
{
    if (command == NULL || shell == NULL)
        return 84;
    dprintf(2, "suspend: Not Implemented.\n");
    shell_set_code(shell, 1);
    return 0;
}
