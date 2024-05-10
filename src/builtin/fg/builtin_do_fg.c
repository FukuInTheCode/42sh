/*
** EPITECH PROJECT, 2024
** builtin_do_fg.c
** File description:
** builtin_do_fg.c
*/

#include "my.h"

int builtin_do_fg(command_t *command, shell_t *shell)
{
    if (command == NULL || shell == NULL)
        return 84;
    dprintf(2, "fg: Not Implemented.\n");
    shell_set_code(shell, 1);
    return 0;
}
