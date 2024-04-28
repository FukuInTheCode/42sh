/*
** EPITECH PROJECT, 2024
** command_handle_toomanyclose_error.c
** File description:
** command_handle_toomanyclose_error.c
*/

#include "command.h"
#include "my.h"
#include "shell.h"

int command_handle_toomanyclose_error(command_t *command, void *shell)
{
    long count = 0;

    if (!command || command->prev)
        return 0;
    for (; command; command = command_get_next(command))
        count += (command_get_type(command) == SUBSHELL_OPEN) -
            (command_get_type(command) == SUBSHELL_CLOSE);
    if (count >= 0)
        return 0;
    shell_set_code(shell, 1);
    return 1;
}
