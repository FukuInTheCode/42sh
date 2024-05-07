/*
** EPITECH PROJECT, 2024
** builtin_free_linked_list_set.c
** File description:
** builtin_free_linked_list_set.c
*/

#include "my.h"
#include "stdlib.h"

int set_destroy(shell_t *shell)
{
    variables_t *current = shell->head;
    variables_t *next = NULL;

    if (current == NULL)
        return 0;
    while (current != NULL) {
        next = current->next;
        free(current->assigned);
        free(current->to_doux);
        free(current);
        current = next;
    }
    return 0;
}