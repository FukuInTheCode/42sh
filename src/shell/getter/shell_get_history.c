/*
** EPITECH PROJECT, 2024
** shell_get_in.c
** File description:
** shell_get_history.c
*/

#include "my.h"

history_t *shell_get_history(shell_t *shell)
{
    return shell->history;
}
