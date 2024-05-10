/*
** EPITECH PROJECT, 2024
** builtin_do_dirs.c
** File description:
** builtin_do_dirs.c
*/

#include "my.h"

int builtin_do_dirs(command_t *command, shell_t *shell)
{
    if (command == NULL || shell == NULL)
        return 84;
    dprintf(2, "dirs: Not Implemented.\n");
    shell_set_code(shell, 1);
    return 0;
}
