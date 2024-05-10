/*
** EPITECH PROJECT, 2024
** command_handle_output_error.c
** File description:
** command_handle_output_error.c
*/

#include "command.h"
#include "my.h"

int command_handle_output_error(command_t *command, void *shell_ptr)
{
    type_t type = command_get_type(command);

    if (type != RIGHT_RED && type != DOUBLE_RIGHT_RED)
        return 0;
    command = command_get_next(command);
    for (; command; command = command_get_next(command)) {
        if (command_get_type(command) == END ||
            command_get_type(command) == SUBSHELL_OPEN ||
            command_get_type(command) == SUBSHELL_CLOSE)
            return 0;
        if (command_get_type(command) == PIPELINE ||
            command_get_type(command) == RIGHT_RED ||
            command_get_type(command) == DOUBLE_RIGHT_RED) {
            shell_set_code(shell_ptr, 1);
            return 1;
        }
    }
    return 0;
}
