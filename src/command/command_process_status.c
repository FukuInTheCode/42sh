/*
** EPITECH PROJECT, 2024
** command_process_status.c
** File description:
** command_process_status.c
*/

#include "my.h"
#include <stdlib.h>

int command_process_status(command_t *command, void *shell)
{
    if (!command || !shell)
        return 84;
    if (WIFEXITED(command_get_status(command))) {
        shell_set_code(shell, WEXITSTATUS(command_get_status(command)));
        return 0;
    }
    command_process_status_error(command, shell);
    return 0;
}
