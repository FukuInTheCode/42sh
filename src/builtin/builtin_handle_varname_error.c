/*
** EPITECH PROJECT, 2024
** builtin_handle_varname_error.c
** File description:
** builtin_handle_varname_error.c
*/

#include "my.h"

int builtin_handle_varname_error(shell_t *shell, char const *var)
{
    if (!var) {
        shell_set_code(shell, 1);
        return 1;
    }
    for (size_t i = 0; var[i]; i++)
        if (!('a' <= var[i] && var[i] <= 'z') &&
            !('A' <= var[i] && var[i] <= 'Z') &&
            !('0' <= var[i] && var[i] <= '9') &&
            var[i] != '_'){
            shell_set_code(shell, 1);
            return 1;
        }
    return 0;
}
