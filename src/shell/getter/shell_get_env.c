/*
** EPITECH PROJECT, 2024
** shell_get_env.c
** File description:
** shell_get_env.c
*/

#include "my.h"

char **shell_get_env(shell_t *shell)
{
    return shell->env;
}
