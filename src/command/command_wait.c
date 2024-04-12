/*
** EPITECH PROJECT, 2024
** command_wait.c
** File description:
** command_wait.c
*/

#include "command.h"
#include "my.h"
#include <sys/wait.h>

int command_wait(command_t *command, void *shell)
{
    if (!command_get_wait(command) || !command_get_pid(command))
        return 0;
    waitpid(command_get_pid(command), &command->status, 0);
    command_process_status(command, shell);
    return 0;
}
