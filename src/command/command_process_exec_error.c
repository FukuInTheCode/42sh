/*
** EPITECH PROJECT, 2024
** command_process_exec_error.c
** File description:
** command_process_exec_error.c
*/

#include "my.h"

#include <errno.h>

int command_process_exec_error(command_t *command, void *shell)
{
    int error = errno;

    if (!command || !shell)
        return 84;
    for (size_t i = 0; exec_errors[i].f; i++) {
        if (exec_errors[i].f(shell, error)) {
            dprintf(2, "%s", command->argv[0]);
            error_put((void *)(exec_errors + i));
            return 1;
        }
    }
    return 0;
}
