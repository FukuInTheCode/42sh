/*
** EPITECH PROJECT, 2024
** builtin_do_time.c
** File description:
** builtin_do_time.c
*/

#include "my.h"

int builtin_do_time(command_t *command, shell_t *shell)
{
    if (command == NULL || shell == NULL)
        return 84;
    dprintf(2, "time: Not Implemented.
");
    shell_set_code(shell, 1);
    return 0;
}
