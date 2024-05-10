/*
** EPITECH PROJECT, 2024
** builtin_do_telltc.c
** File description:
** builtin_do_telltc.c
*/

#include "my.h"

int builtin_do_telltc(command_t *command, shell_t *shell)
{
    if (command == NULL || shell == NULL)
        return 84;
    dprintf(2, "telltc: Not Implemented.
");
    shell_set_code(shell, 1);
    return 0;
}
