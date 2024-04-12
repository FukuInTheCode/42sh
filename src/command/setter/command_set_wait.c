/*
** EPITECH PROJECT, 2024
** command_set_wait.c
** File description:
** command_set_wait.c
*/

#include "my.h"

int command_set_wait(command_t *command, bool do_wait)
{
    command->do_wait = do_wait;
    return 0;
}
