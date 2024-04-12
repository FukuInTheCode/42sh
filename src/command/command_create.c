/*
** EPITECH PROJECT, 2024
** command_create.c
** File description:
** command_create.c
*/

#include "my.h"
#include "shell.h"
#include <stdlib.h>

command_t *command_create(void)
{
    command_t *command = calloc(1, sizeof(command_t));

    if (!command)
        return NULL;
    command->argv = calloc(1, sizeof(char *));
    if (!command->argv) {
        free(command->argv);
        return NULL;
    }
    command_set_in(command, SYS_IN);
    command_set_out(command, SYS_OUT);
    command_set_err(command, SYS_ERR);
    return command;
}
