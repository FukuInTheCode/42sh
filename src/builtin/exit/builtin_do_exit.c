/*
** EPITECH PROJECT, 2024
** builtin_do_exit.c
** File description:
** builtin_do_exit.c
*/

#include "error.h"
#include "my.h"
#include "builtins.h"
#include <stdint.h>
#include <stdlib.h>

static int exit_handle_error(command_t *command, shell_t *shell)
{
    for (size_t i = 0; exit_errors[i].f; i++) {
        if (exit_errors[i].f(command, shell)) {
            error_put((void *)(exit_errors + i));
            return 1;
        }
    }
    return 0;
}

static int set_exit_code(command_t *command, shell_t *shell)
{
    char *end_ptr = NULL;

    if (command_get_argc(command) == 1) {
        shell_set_code(shell, 0);
        return 0;
    }
    shell_set_code(shell, strtol(command_get_argv(command)[1], &end_ptr, 10));
    return 0;
}

int builtin_do_exit(command_t *command, shell_t *shell)
{
    if (exit_handle_error(command, shell))
        return 0;
    if (command_get_argc(command) == 2)
        set_exit_code(command, shell);
    shell_set_exit(shell, true);
    printf("exit\n");
    return 0;
}
