/*
** EPITECH PROJECT, 2024
** command_get_next.c
** File description:
** command_get_next.c
*/

#include "my.h"

////////////////////////////////////////////////////////////
// command_t *command_get_next(command_t *command)
//
// command -> structure that contains all the data of the
// current command
//
// This function returns the next command_t structure.
//
// RETURN VALUE : command_t * that returns the value of the
// next command_t structure.
////////////////////////////////////////////////////////////
command_t *command_get_next(command_t *command)
{
    return command->next;
}
