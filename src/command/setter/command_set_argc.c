/*
** EPITECH PROJECT, 2024
** command_set_argc.c
** File description:
** command_set_argc.c
*/

#include "command.h"
#include "my.h"

int command_set_argc(command_t *command, int argc)
{
    command->argc = argc;
    return 0;
}
