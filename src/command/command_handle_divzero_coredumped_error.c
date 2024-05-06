/*
** EPITECH PROJECT, 2024
** command_handle_segfault_coredumped_error.c
** File description:
** command_handle_segfault_coredumped_error.c
*/

#include "my.h"
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>

int command_handle_divzero_coredumped_error(void *shell, int status)
{
    if (WTERMSIG(status) == SIGFPE && WCOREDUMP(status)) {
        shell_set_code(shell, 128 + WTERMSIG(status));
        return 1;
    }
    return 0;
}
