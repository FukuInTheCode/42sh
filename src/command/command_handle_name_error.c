/*
** EPITECH PROJECT, 2024
** command_handle_name_error.c
** File description:
** command_handle_name_error.c
*/

#include "command.h"
#include "my.h"

int command_handle_name_error(command_t *command, void *shell_ptr)
{
    type_t type = command_get_type(command);
    command_t *next = NULL;

    if (type != LEFT_RED && type != DOUBLE_LEFT_RED &&
        type != RIGHT_RED && type != DOUBLE_RIGHT_RED)
        return 0;
    next = command_get_next(command);
    if (!next || command_get_type(next) != OTHER) {
        shell_set_code(shell_ptr, 1);
        return 1;
    }
    return 0;
}
