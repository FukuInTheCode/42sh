/*
** EPITECH PROJECT, 2024
** builtin_do_echo.c
** File description:
** builtin_do_echo.c
*/

#include "shell.h"
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

int builtin_do_echo(command_t *command, shell_t *shell)
{
    bool print_new_line = true;

    for (int i = 1; i < command->argc; i++) {
        if (!strcmp("-n", command->argv[i])) {
            print_new_line = false;
            continue;
        }
        if (i != 0)
            printf(" ");
        printf("%s", command->argv[i]);
    }
    if (print_new_line)
        printf("\n");
    shell_set_code(shell, 0);
    return 0;
}
