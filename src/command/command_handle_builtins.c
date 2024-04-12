/*
** EPITECH PROJECT, 2024
** command_handle_builtins.c
** File description:
** command_handle_builtins.c
*/

#include "builtins.h"
#include "my.h"
#include <string.h>

int command_handle_builtins(command_t *command)
{
    for (size_t i = 0; builtins[i].name; i++) {
        if (!strcmp(builtins[i].name, command_get_path(command)))
            return 1;
    }
    return 0;
}
