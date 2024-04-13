/*
** EPITECH PROJECT, 2024
** builtin_handle_varfirst_error.c
** File description:
** builtin_handle_varfirst_error.c
*/

#include "my.h"

int builtin_handle_varfirst_error(shell_t *shell, char const *var)
{
    if (!var || (!('a' <= *var && *var <= 'z') &&
        !('A' <= *var && *var <= 'Z') && *var != '_')) {
        shell_set_code(shell, 1);
        return 1;
    }
    return 0;
}
