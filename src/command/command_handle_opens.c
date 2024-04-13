/*
** EPITECH PROJECT, 2024
** command_handle_opens.c
** File description:
** command_handle_opens.c
*/

#include "my.h"
#include "shell.h"

#include <unistd.h>

int command_handle_opens(command_t *command)
{
    if (command_handle_builtins(command) &&
        command_get_out(command) == SYS_OUT)
        return 0;
    if (command_get_out(command) != SYS_OUT)
        dup2(command_get_out(command), SYS_OUT);
    if (command_get_in(command) != SYS_IN)
        dup2(command_get_in(command), SYS_IN);
    if (command_get_err(command) != SYS_ERR)
        dup2(command_get_err(command), SYS_ERR);
    return 0;
}
