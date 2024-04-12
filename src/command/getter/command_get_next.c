/*
** EPITECH PROJECT, 2024
** command_get_next.c
** File description:
** command_get_next.c
*/

#include "my.h"

command_t *command_get_next(command_t *command)
{
    return command->next;
}
