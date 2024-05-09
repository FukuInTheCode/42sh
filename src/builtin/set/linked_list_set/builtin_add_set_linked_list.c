/*
** EPITECH PROJECT, 2024
** builtin_add_set_linked_list.c
** File description:
** builtin_add_set_linked_list.c
*/

#include "my.h"
#include "shell.h"
#include <stdlib.h>
#include <string.h>

static variables_t *create_node_set(char *assigned, char *need_to_do)
{
    variables_t *new = NULL;

    if (assigned == NULL)
        return NULL;
    new = (variables_t *)calloc(1, sizeof(variables_t));
    if (new == NULL)
        return NULL;
    new->assigned = strdup(assigned);
    if (need_to_do != NULL)
        new->to_do = strdup(need_to_do);
    else
        new->to_do = NULL;
    return new;
}

static int change_value(variables_t *current, char *assigned, char *need_to_do)
{
    if (strcmp(assigned, current->assigned) == 0) {
        free(current->to_do);
        current->to_do = NULL;
        if (need_to_do)
            current->to_do = strdup(need_to_do);
        return 0;
    }
    return 1;
}

static void browse_linked_list(variables_t *current, variables_t *new,
    char *assigned, char *need_to_do)
{
    bool is_in = false;
    variables_t *prev = NULL;

    while (current != NULL) {
        if (change_value(current, assigned, need_to_do) == 0)
            is_in = true;
        prev = current;
        current = current->next;
    }
    if (is_in == false)
        prev->next = new;
    else {
        free(new->assigned);
        free(new->to_do);
        free(new);
    }
}

void add_linked_list_set(char *assigned, char *need_to_do, shell_t *shell)
{
    variables_t *new = create_node_set(assigned, need_to_do);
    variables_t *current = NULL;

    if (new == NULL)
        return;
    if (shell->head == NULL)
        shell->head = new;
    else {
        current = shell->head;
        browse_linked_list(current, new, assigned, need_to_do);
    }
}
