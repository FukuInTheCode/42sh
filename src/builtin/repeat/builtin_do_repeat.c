/*
** EPITECH PROJECT, 2024
** builtin_do_repeat.c
** File description:
** builtin_do_repeat.c
*/

#include "builtins.h"
#include "command.h"
#include "my.h"
#include "shell.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int create_command(shell_t *shell,
    long n, char **argv, command_t *repeat)
{
    command_t *command = NULL;

    if (n < 1)
        return 0;
    command = command_copy(repeat);
    if (!command)
        return 84;
    command_set_argv(command, my_copy_word_array(argv));
    command_set_wait(command, true);
    command->path = NULL;
    command_process_path(command, (void *)shell);
    for (long i = 0; i < n; i++) {
        command_exec(command, (void *)shell);
        command_wait(command, (void *)shell);
    }
    shell_set_code(shell, command_get_status(command));
    command_destroy(command);
    return 0;
}

int builtin_do_repeat(command_t *command, shell_t *shell)
{
    int argc = 0;
    char **argv = NULL;
    long n = 0L;
    char *end_ptr = NULL;

    if (!command || !shell)
        return 84;
    argc = command_get_argc(command);
    argv = command_get_argv(command);
    if (argc < 3) {
        dprintf(2, "repeat: Too few arguments.\n");
        return shell_set_code(shell, 1);
    }
    n = strtol(argv[1], &end_ptr, 10);
    if (end_ptr != argv[1] + strlen(argv[1])) {
        dprintf(2, "repeat: Badly formed number.\n");
        return shell_set_code(shell, 1);
    }
    return create_command(shell, n, argv + 2, command);
}
