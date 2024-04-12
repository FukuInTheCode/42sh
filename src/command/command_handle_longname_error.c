/*
** EPITECH PROJECT, 2024
** command_handle_longname_error.c
** File description:
** command_handle_longname_error.c
*/

#include "my.h"

#include <errno.h>

int command_handle_longname_error(void *shell, int error)
{
    if (error != ENAMETOOLONG)
        return 0;
    shell_set_code(shell, 1);
    return 1;
}
