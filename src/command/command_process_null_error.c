/*
** EPITECH PROJECT, 2024
** command_process_null_error.c
** File description:
** command_process_null_error.c
*/

#include "my.h"

int command_process_null_error(command_t *command, command_t *end,
    void *shell_ptr)
{
    myerror_t null_error = {"Invalid null command.\n",
        command_handle_null_error};

    if (!command_get_prev(command) && null_error.f(command, shell_ptr)) {
        error_put(&null_error);
        return 1;
    }
    for (; command && command != end; command = command_get_next(command)) {
        if (null_error.f(command, shell_ptr)) {
            error_put(&null_error);
            return 1;
        }
    }
    return 0;
}
