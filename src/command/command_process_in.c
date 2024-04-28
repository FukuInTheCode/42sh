/*
** EPITECH PROJECT, 2024
** command_process_in.c
** File description:
** command_process_in.c
*/

#include "command.h"
#include "my.h"

int command_process_in(command_t *command, void *shell)
{
    command_t *in = command_get_next(command);
    type_t in_type = 0;

    if (command_get_in(command) == SYS_IN)
        command_set_in(command, shell_get_in(shell));
    for (; in; in = command_get_next(in)) {
        in_type = command_get_type(in);
        if (in_type == END || in_type == PIPELINE ||
            in_type == SUBSHELL_OPEN || in_type == SUBSHELL_CLOSE)
            return 0;
        if (in_type == LEFT_RED)
            return command_handle_left_red(command, in, shell);
        if (in_type == DOUBLE_LEFT_RED)
            return command_handle_double_left_red(command, in, shell);
    }
    return 0;
}
