/*
** EPITECH PROJECT, 2024
** command_set_type.c
** File description:
** command_set_type.c
*/

#include "my.h"

int command_set_type(command_t *command, type_t type)
{
    command->type = type;
    return 0;
}
