/*
** EPITECH PROJECT, 2024
** command_copy.c
** File description:
** command_copy.c
*/

#include "command.h"
#include "my.h"
#include <string.h>

command_t *command_copy(command_t *command)
{
    command_t *copy = NULL;

    if (!command)
        return NULL;
    copy = command_create();
    if (!copy)
        return NULL;
    memcpy(copy, command, sizeof(command_t));
    copy->argv = my_copy_word_array(command_get_argv(command));
    command_set_prev(copy, NULL);
    command_set_next(copy, NULL);
    return copy;
}
