/*
** EPITECH PROJECT, 2024
** command_add.c
** File description:
** command_add.c
*/

#include "my.h"

int command_add(command_t *head, command_t *to_add)
{
    for (; head->next; head = command_get_next(head));
    command_set_next(head, to_add);
    return 0;
}
