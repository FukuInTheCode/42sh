/*
** EPITECH PROJECT, 2024
** shell_set_cmds.c
** File description:
** shell_set_cmds.c
*/

#include "my.h"

int shell_set_cmds(shell_t *shell, command_t *cmds)
{
    shell->cmds = cmds;
    return 0;
}
