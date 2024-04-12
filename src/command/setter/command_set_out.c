/*
** EPITECH PROJECT, 2024
** command_set_out.c
** File description:
** command_set_out.c
*/

#include "my.h"

int command_set_out(command_t *command, int out)
{
    command->out = out;
    return 0;
}
