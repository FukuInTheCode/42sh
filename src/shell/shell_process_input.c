/*
** EPITECH PROJECT, 2024
** shell_process_input.c
** File description:
** shell_process_input.c
*/

#include "my.h"
#include <stdio.h>
#include "variables.h"
#include <stdlib.h>

int shell_process_input(shell_t *shell, char const *input)
{
    char *new_input = variables_format(input, shell);

    if (new_input == NULL)
        return 0;
    shell_parse_input(shell, new_input);
    if (shell_process_cmds_error(shell) == 1)
        return 0;
    shell_process_commands(shell);
    return 0;
}
