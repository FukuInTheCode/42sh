/*
** EPITECH PROJECT, 2024
** 42sh-mirror
** File description:
** remove_history.c
*/

#include <stdlib.h>
#include "shell.h"
#include <stdio.h>

void remove_history(shell_t *shell)
{
    history_t *history = shell_get_history(shell);
    history_t *tmp;

    if (history && history->id)
        shell_set_history_id(shell, history->id);
    while (history) {
        tmp = history;
        history = history->next;
        free(tmp->line);
        free(tmp);
    }
    shell_set_history(shell, NULL);
}
