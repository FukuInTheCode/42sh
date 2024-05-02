/*
** EPITECH PROJECT, 2024
** is_builtin.c
** File description:
** is_builtin.c
*/

#include "my.h"
#include "builtins.h"
#include <string.h>

bool is_builtin(char *argv)
{
    for (size_t i = 0; builtins[i].name != NULL; i++) {
        if (!strcmp(builtins[i].name, argv)) {
            return true;
        }
    }
    return false;
}
