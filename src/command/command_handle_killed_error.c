/*
** EPITECH PROJECT, 2024
** command_handle_segfault_error.c
** File description:
** command_handle_segfault_error.c
*/

#include "my.h"

#include <signal.h>
#include <stdlib.h>

int command_handle_killed_error(void *shell, int status)
{
    if (WTERMSIG(status) == SIGXCPU) {
        shell_set_code(shell, 128 + WTERMSIG(status));
        return 1;
    }
    return 0;
}
