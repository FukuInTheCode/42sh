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

int command_handle_closes(command_t *command)
{
    if (command_get_err(command) != SYS_ERR)
        close(command_get_err(command));
    if (command_get_out(command) != SYS_OUT)
        close(command_get_out(command));
    if (command_get_in(command) != SYS_IN)
        close(command_get_in(command));
    return 0;
}
