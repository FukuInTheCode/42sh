/*
** EPITECH PROJECT, 2024
** builtin_remove_set_linked_list.c
** File description:
** builtin_remove_set_linked_list.c
*/

#include "my.h"
#include <string.h>
#include <stdlib.h>

void remove_node_linked_list_set(shell_t *shell, char *assigned)
{
    variables_t *current = shell->head;
    variables_t *prev = NULL;

    if (current == NULL)
        return;
    if (strcmp(current->assigned, assigned) == 0) {
        shell->head = current->next;
        free(current);
        return;
    }
    while (current != NULL && strcmp(current->assigned, assigned) != 0) {
        prev = current;
        current = current->next;
    }
    if (current == NULL)
        return;
    if (prev != NULL)
        prev->next = current->next;
    free(current);
}
