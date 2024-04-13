/*
** EPITECH PROJECT, 2024
** builtin_handle_cd_errors.c
** File description:
** builtin_handle_cd_errors.c
*/

#include "builtins.h"
#include "my.h"

int builtin_handle_cd_errors(shell_t *shell, char const *pwd, int error)
{
    for (size_t i = 0; cd_errors[i].f; i++) {
        if (cd_errors[i].f(shell, error)) {
            dprintf(2, "%s", pwd);
            error_put((void *)(cd_errors + i));
            return 1;
        }
    }
    return 0;
}
