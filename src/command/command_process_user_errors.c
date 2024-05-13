/*
** EPITECH PROJECT, 2024
** command_process_user_errors.c
** File description:
** command_process_user_errors.c
*/

#include "my.h"

////////////////////////////////////////////////////////////
// int command_process_user_errors(command_t *command, void *shell_ptr)
//
// command -> structure that contains all the data of the
// current command
// shell_ptr -> pointer to the shell structure
//
// This function processes the users_errors on command use.
//
// RETURN VALUE : int that is 0 if there is no error, otherwise
// it's 1.
////////////////////////////////////////////////////////////
int command_process_user_errors(command_t *command, void *shell_ptr)
{
    for (size_t i = 0; user_errors[i].f; i++) {
        if (user_errors[i].f(command, shell_ptr)) {
            error_put((void *)(user_errors + i));
            return 1;
        }
    }
    return 0;
}
