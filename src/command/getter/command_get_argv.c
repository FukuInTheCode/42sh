/*
** EPITECH PROJECT, 2024
** command_get_argv.c
** File description:
** command_get_argv.c
*/

#include "my.h"

char **command_get_argv(command_t *command)
{
    return command->argv;
}
