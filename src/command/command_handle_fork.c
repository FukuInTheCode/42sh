/*
** EPITECH PROJECT, 2024
** command_handle_fork.c
** File description:
** command_handle_fork.c
*/

#include "my.h"

#include <unistd.h>

int command_handle_fork(command_t *command)
{
    pid_t pid = 0;

    if (command_handle_builtins(command) &&
        command_get_out(command) == SYS_OUT)
        return 0;
    pid = fork();
    if (pid < 0)
        return 84;
    command_set_pid(command, pid);
    return 0;
}
