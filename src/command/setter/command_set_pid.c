/*
** EPITECH PROJECT, 2024
** command_set_pid.c
** File description:
** command_set_pid.c
*/

#include "my.h"

int command_set_pid(command_t *command, pid_t pid)
{
    command->pid = pid;
    return 0;
}
