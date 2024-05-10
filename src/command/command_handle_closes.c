/*
** EPITECH PROJECT, 2024
** command_handle_closes.c
** File description:
** command_handle_closes.c
*/

#include "command.h"
#include "my.h"
#include "shell.h"
#include <unistd.h>

int command_handle_closes(command_t *command, void *shell)
{
    if (command_get_err(command) != shell_get_err(shell))
        close(command_get_err(command));
    if (command_get_out(command) != shell_get_out(shell))
        close(command_get_out(command));
    if (command_get_in(command) != shell_get_in(shell))
        close(command_get_in(command));
    return 0;
}
