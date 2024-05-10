/*
** EPITECH PROJECT, 2024
** command_handle_null_error.c
** File description:
** command_handle_null_error.c
*/

#include "command.h"
#include "shell.h"
#include <stdio.h>

static bool check_prev(command_t *command)
{
    command_t *prev = command_get_prev(command);
    type_t type = 0;

    if (!prev)
        return false;
    type = command_get_type(prev);
    if (type != COMMAND && type != OTHER && type != SUBSHELL_CLOSE)
        return false;
    return true;
}

static bool check_next(command_t *command)
{
    command_t *next = command_get_next(command);
    type_t type = 0;

    if (!next)
        return false;
    type = command_get_type(next);
    if (type != COMMAND && type != OTHER && type != SUBSHELL_OPEN)
        return false;
    return true;
}

static int handle_and(command_t *command)
{
    command_t *next = command_get_next(command);
    command_t *prev = command_get_prev(command);

    if (!prev && !next)
        return 0;
    if (check_prev(command) && !check_next(command))
        return 1;
    return 0;
}

int command_handle_null_error(command_t *command, void *shell_ptr)
{
    type_t type = command_get_type(command);

    if (type != PIPELINE && type != LEFT_RED &&
        type != DOUBLE_RIGHT_RED && type != DOUBLE_LEFT_RED &&
        type != RIGHT_RED && type != AND && type != OR)
        return 0;
    if (type == AND) {
        shell_set_code(shell_ptr, handle_and(command));
        return shell_get_code(shell_ptr);
    }
    if (!check_prev(command) || !check_next(command)) {
        shell_set_code(shell_ptr, 1);
        return 1;
    }
    return 0;
}
