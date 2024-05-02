/*
** EPITECH PROJECT, 2024
** shell_set_history.c
** File description:
** shell_set_history.c
*/

#include "my.h"

int shell_set_history(shell_t *shell, history_t *history)
{
    shell->history = history;
    return 0;
}
