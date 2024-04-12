/*
** EPITECH PROJECT, 2024
** builtin_handle_cd_access_error.c
** File description:
** builtin_handle_cd_access_error.c
*/

#include "my.h"
#include <errno.h>

int builtin_handle_cd_access_error(shell_t *shell, int error)
{
    if (error == EACCES) {
        shell_set_code(shell, 1);
        return 1;
    }
    return 0;
}
