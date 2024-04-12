/*
** EPITECH PROJECT, 2024
** command_set_status.c
** File description:
** command_set_status.c
*/

#include "my.h"

int command_set_status(command_t *command, int status)
{
    command->status = status;
    return 0;
}
