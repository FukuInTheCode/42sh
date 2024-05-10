/*
** EPITECH PROJECT, 2024
** builtin_do_unset.c
** File description:
** builtin_do_unset.c
*/

#include "builtins.h"
#include "command.h"
#include "shell.h"
#include <stdio.h>

int builtin_do_unset(command_t *command, shell_t *shell)
{
    char **argv = command_get_argv(command);

    if (command_get_argc(command) == 1) {
        dprintf(2, "unset: Too few arguments.\n");
        shell_set_code(shell, 1);
        return 0;
    }
    for (size_t i = 0; argv[i]; i++)
        remove_node_linked_list_set(shell, argv[i]);
    shell_set_code(shell, 0);
    return 0;
}
