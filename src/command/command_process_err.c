/*
** EPITECH PROJECT, 2024
** command_process_err.c
** File description:
** command_process_err.c
*/

#include "my.h"
#include "shell.h"

int command_process_err(command_t *command, void *shell)
{
    if (shell_get_err(shell) != SYS_ERR)
        command_set_err(command, shell_get_err(shell));
    return 0;
}
