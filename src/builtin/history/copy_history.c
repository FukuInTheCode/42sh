/*
** EPITECH PROJECT, 2024
** 42sh-mirror
** File description:
** copy_history.c
*/

#include "history.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static history_t *init_copy(history_t *copy, history_t *history_tmp)
{
    copy = malloc(sizeof(history_t));
    copy->id = history_tmp->id;
    copy->line = strdup(history_tmp->line);
    copy->time = history_tmp->time;
    copy->prev = NULL;
    history_tmp = history_tmp->next;
    return copy;
}

history_t *copy_history(history_t *history)
{
    history_t *history_tmp = history;
    history_t *copy = NULL;
    history_t *copy_tmp;

    if (!history)
        return NULL;
    copy = init_copy(copy, history_tmp);
    copy_tmp = copy;
    while (history_tmp->next) {
        copy_tmp->next = malloc(sizeof(history_t));
        copy_tmp->next->id = history_tmp->next->id;
        copy_tmp->next->line = strdup(history_tmp->next->line);
        copy_tmp->next->time = history_tmp->next->time;
        copy_tmp->next->prev = copy_tmp;
        history_tmp = history_tmp->next;
        copy_tmp = copy_tmp->next;
    }
    copy_tmp->next = NULL;
    return copy;
}
