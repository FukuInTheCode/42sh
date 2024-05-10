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

////////////////////////////////////////////////////////////
// int shell_process_input(shell_t *shell, char const *input)
//
// shell -> structure that contains all the data of the shell
// input -> string that represent the input of the user
//
// This function parse and process the input and detect the errors
// to execute commands.
//
// RETURN VALUE : int that is always 0
////////////////////////////////////////////////////////////
int shell_process_input(shell_t *shell, char const *input)
{
    char *new_input = variables_format(input, shell);

    if (new_input == NULL)
        return 0;
    shell_parse_input(shell, new_input);
    if (shell_process_cmds_error(shell) == 1)
        return 0;
    shell_process_commands(shell);
    free(new_input);
    return 0;
}
