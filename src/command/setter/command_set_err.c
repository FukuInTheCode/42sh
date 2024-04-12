/*
** EPITECH PROJECT, 2024
** command_set_err.c
** File description:
** command_set_err.c
*/

#include "my.h"

int command_set_err(command_t *command, int err)
{
    command->err = err;
    return 0;
}
