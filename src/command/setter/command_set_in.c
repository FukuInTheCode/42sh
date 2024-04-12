/*
** EPITECH PROJECT, 2024
** command_set_in.c
** File description:
** command_set_in.c
*/

#include "my.h"

int command_set_in(command_t *command, int in)
{
    command->in = in;
    return 0;
}
