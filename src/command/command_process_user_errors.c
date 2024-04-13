/*
** EPITECH PROJECT, 2024
** command_process_user_errors.c
** File description:
** command_process_user_errors.c
*/

#include "my.h"

int command_process_user_errors(command_t *command, void *shell_ptr)
{
    for (size_t i = 0; user_errors[i].f; i++) {
        if (user_errors[i].f(command, shell_ptr)) {
            error_put((void *)(user_errors + i));
            return 1;
        }
    }
    return 0;
}
