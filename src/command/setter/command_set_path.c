/*
** EPITECH PROJECT, 2024
** command_set_path.c
** File description:
** command_set_path.c
*/

#include "my.h"

#include <stdlib.h>
#include <string.h>

int command_set_path(command_t *command, char const *path)
{
    free(command_get_path(command));
    command->path = strdup(path);
    return 0;
}
