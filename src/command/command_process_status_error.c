/*
** EPITECH PROJECT, 2024
** command_process_status_error.c
** File description:
** command_process_status_error.c
*/

#include "my.h"

int command_process_status_error(command_t *command, void *shell)
{
    if (!command || !shell)
        return 84;
    for (size_t i = 0; status_errors[i].f; i++) {
        if (status_errors[i].f(shell, command_get_status(command))) {
            error_put((void *)(status_errors + i));
            return 0;
        }
    }
    return 0;
}
