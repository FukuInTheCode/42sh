/*
** EPITECH PROJECT, 2024
** builtin_get_variables.c
** File description:
** builtin_get_variables.c
*/

#include "my.h"
#include <string.h>

char *get_assigned_variable(char **argv, int *i, char *assigned)
{
    if (strcmp(argv[*i], "=") == 0) {
        assigned = argv[*i - 1];
        (*i)++;
    } else if (argv[*i + 1] == NULL || strcmp(argv[*i + 1], "=") != 0)
        assigned = argv[*i];
    return assigned;
}

char *get_to_doux_variable(char **argv, int i, char *need_to_do)
{
    if (strcmp(argv[i - 1], "=") == 0)
        need_to_do = argv[i];
    return need_to_do;
}
