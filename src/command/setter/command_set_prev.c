/*
** EPITECH PROJECT, 2024
** command_set_prev.c
** File description:
** command_set_prev.c
*/

#include "my.h"

int command_set_prev(command_t *command, command_t *prev)
{
    command->prev = prev;
    if (prev && command_get_next(prev) != command)
        command_set_next(prev, command);
    return 0;
}
