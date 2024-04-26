/*
** EPITECH PROJECT, 2024
** command_handle_badly_error.c
** File description:
** command_handle_badly_error.c
*/

#include "command.h"
#include "my.h"

int command_handle_badly_error(command_t *command, void *shell)
{
    if (!command || (command_get_type(command) != SUBSHELL_CLOSE &&
        command_get_type(command) != SUBSHELL_OPEN))
        return 0;
    if (command_get_type(command) == SUBSHELL_OPEN && command->prev &&
        (command_get_type(command->prev) == COMMAND ||
        command_get_type(command->prev) == OTHER)) {
        shell_set_code(shell, 1);
        return 1;
    }
    if (command_get_type(command) == SUBSHELL_CLOSE && command->next &&
        (command_get_type(command->next) == COMMAND ||
        command_get_type(command->next) == OTHER)) {
        shell_set_code(shell, 1);
        return 1;
    }
    return 0;
}
