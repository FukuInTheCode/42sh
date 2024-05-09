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
    int size = 0;

    if (history == NULL || history->next == NULL)
        return;
    while (history->next->next && strcmp(history->next->line, line) != 0
    && size <= 100) {
        history = history->next;
        size++;
    }
    if (size >= 100 || strcmp(history->next->line, line) == 0) {
        tmp = history->next;
        history->next = history->next->next;
        free(tmp->line);
        free(tmp);
    }
    return;
}

static history_t *create_new_history_node(shell_t *shell, char *line)
{
    history_t *new = malloc(sizeof(history_t));

    new->line = strdup(line);
    new->time = time(NULL);
    new->prev = NULL;
    new->next = shell_get_history(shell);
    if (new->next)
        new->id = new->next->id + 1;
    else {
        new->id = shell_get_history_id(shell);
        shell_set_history_id(shell, shell_get_history_id(shell) + 1);
    }
    return new;
}

void add_in_history(shell_t *shell, char *line)
{
    history_t *history = shell_get_history(shell);
    history_t *new;

    if (strcmp(line, "") == 0)
        return;
    if (history && strcmp(history->line, line) == 0) {
        history->id++;
        history->time = time(NULL);
        return;
    }
    remove_in_history(history, line);
    new = create_new_history_node(shell, line);
    if (history)
        history->prev = new;
    shell_set_history(shell, new);
}
