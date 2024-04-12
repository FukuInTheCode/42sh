/*
** EPITECH PROJECT, 2024
** command_handle_null_error.c
** File description:
** command_handle_null_error.c
*/

#include "command.h"
#include "my.h"


static int check_neighbor(command_t *command, shell_t *shell)
{
    type_t type = command_get_type(command_get_next(command));

    if (type != COMMAND && type != OTHER) {
        shell_set_code(shell, 1);
        return 1;
    }
    type = command_get_type(command_get_next(command));
    if (type != COMMAND && type != OTHER) {
        shell_set_code(shell, 1);
        return 1;
    }
    return 0;
}

int command_handle_null_error(command_t *command, void *shell_ptr)
{
    type_t type = command_get_type(command);

    if (type != PIPELINE && type != LEFT_RED &&
        type != DOUBLE_RIGHT_RED && type != DOUBLE_LEFT_RED &&
        type != RIGHT_RED)
        return 0;
    if (!command_get_prev(command) || !command_get_next(command)) {
        shell_set_code(shell_ptr, 1);
        return 1;
    }
    return check_neighbor(command, shell_ptr);
}
