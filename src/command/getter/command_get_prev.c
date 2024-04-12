/*
** EPITECH PROJECT, 2024
** command_get_prev.c
** File description:
** command_get_prev.c
*/

#include "my.h"

command_t *command_get_prev(command_t *command)
{
    return command->prev;
}
