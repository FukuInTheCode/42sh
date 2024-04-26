/*
** EPITECH PROJECT, 2024
** 42sh-mirror
** File description:
** remove_history.c
*/

#include <stdlib.h>
#include "shell.h"

void remove_history(shell_t *shell)
{
    history_t *history = shell->history;
    history_t *temp;

    shell->history_id = history->id;
    while (history) {
        temp = history;
        history = history->next;
        free(temp);
    }
    shell->history = NULL;
}
