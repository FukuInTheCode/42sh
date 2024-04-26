/*
** EPITECH PROJECT, 2024
** 42sh-mirror
** File description:
** add_in_history.c
*/

#include "history.h"
#include <stdlib.h>
#include <string.h>

static void remove_in_history(history_t *history, char *line)
{
    history_t *tmp;

    if (history == NULL || history->next == NULL)
        return;
    while (history->next->next && strcmp(history->next->line, line) != 0)
        history = history->next;
    if (strcmp(history->next->line, line) == 0) {
        tmp = history->next;
        history->next = history->next->next;
        free(tmp);
    }
    return;
}

void add_in_history(history_t **history_ptr, char *line, shell_t *shell)
{
    history_t *new;

    if (strcmp(line, "\n") == 0)
        return;
    if (*history_ptr && strcmp((*history_ptr)->line, line) == 0) {
        (*history_ptr)->id++;
        return;
    }
    new = malloc(sizeof(history_t));
    remove_in_history(*history_ptr, line);
    new->line = strdup(line);
    new->time = time(NULL);
    new->prev = NULL;
    new->next = (*history_ptr);
    if (new->next)
        new->id = new->next->id + 1;
    else
        new->id = shell->history_id + 1;
    if (*history_ptr)
        (*history_ptr)->prev = new;
    *history_ptr = new;
}
