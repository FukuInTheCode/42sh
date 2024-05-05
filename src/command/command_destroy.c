/*
** EPITECH PROJECT, 2024
** command_destroy.c
** File description:
** command_destroy.c
*/

#include "my.h"
#include <stdlib.h>


////////////////////////////////////////////////////////////
// int command_destroy(command_t *command)
//
// command -> structure that contains all the data of the
// current command
//
// This function frees the command passed as parameters.
//
// RETURN VALUE : int that is always 0
////////////////////////////////////////////////////////////
int command_destroy(command_t *command)
{
    if (!command)
        return 0;
    command_destroy(command_get_next(command));
    my_free_word_array(command_get_argv(command));
    free(command);
    return 0;
}
