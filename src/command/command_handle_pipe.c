/*
** EPITECH PROJECT, 2024
** command_handle_pipe.c
** File description:
** command_handle_pipe.c
*/

#include "my.h"

#include <unistd.h>

int command_handle_pipe(command_t *command, command_t *pipecmd, void *shell)
{
    int fds[2] = {0};

    if (!shell)
        return 84;
    if (pipe(fds))
        return 84;
    command_set_out(command, fds[1]);
    command_set_in(command_get_next(pipecmd), fds[0]);
    return 0;
}
