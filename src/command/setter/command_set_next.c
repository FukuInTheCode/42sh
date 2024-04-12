/*
** EPITECH PROJECT, 2024
** command_set_next.c
** File description:
** command_set_next.c
*/

#include "command.h"
#include "my.h"

int command_set_next(command_t *command, command_t *next)
{
    command->next = next;
    if (next && command_get_prev(next) != command)
        command_set_prev(next, command);
    return 0;
}
