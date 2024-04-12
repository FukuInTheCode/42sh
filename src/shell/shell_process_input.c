/*
** EPITECH PROJECT, 2024
** shell_process_input.c
** File description:
** shell_process_input.c
*/

#include "my.h"
#include <stdio.h>

int shell_process_input(shell_t *shell, char const *input)
{
    shell_parse_input(shell, input);
    if (shell_process_cmds_error(shell) == 1)
        return 0;
    shell_process_commands(shell);
    return 0;
}
