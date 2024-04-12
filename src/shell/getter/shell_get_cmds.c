/*
** EPITECH PROJECT, 2024
** shell_get_cmds.c
** File description:
** shell_get_cmds.c
*/

#include "my.h"

command_t *shell_get_cmds(shell_t *shell)
{
    return shell->cmds;
}
