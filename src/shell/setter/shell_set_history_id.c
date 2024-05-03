/*
** EPITECH PROJECT, 2024
** shell_set_history_id.c
** File description:
** shell_set_history_id.c
*/

#include "my.h"

int shell_set_history_id(shell_t *shell, int history_id)
{
    shell->history_id = history_id;
    return 0;
}
