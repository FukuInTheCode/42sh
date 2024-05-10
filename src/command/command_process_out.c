/*
** EPITECH PROJECT, 2024
** command_process_out.c
** File description:
** command_process_out.c
*/

#include "my.h"
#include "shell.h"

int command_process_out(command_t *command, void *shell)
{
    command_t *out = command_get_next(command);
    type_t out_type = 0;

    command_set_out(command, shell_get_out(shell));
    for (; out; out = command_get_next(out)) {
        out_type = command_get_type(out);
        if (out_type == END ||
            out_type == SUBSHELL_OPEN || out_type == SUBSHELL_CLOSE)
            return 0;
        if (out_type == PIPELINE)
            return command_handle_pipe(command, out, shell);
        if (out_type == RIGHT_RED)
            return command_handle_right_red(command, out, shell);
        if (out_type == DOUBLE_RIGHT_RED)
            return command_handle_double_right_red(command, out, shell);
    }
    return 0;
}
