/*
** EPITECH PROJECT, 2024
** builtin_do_termname.c
** File description:
** builtin_do_termname.c
*/

#include "my.h"

int builtin_do_termname(command_t *command, shell_t *shell)
{
    if (command == NULL || shell == NULL)
        return 84;
    dprintf(2, "termname: Not Implemented.
");
    shell_set_code(shell, 1);
    return 0;
}
