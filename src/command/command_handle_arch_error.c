/*
** EPITECH PROJECT, 2024
** command_handle_arch_error.c
** File description:
** command_handle_arch_error.c
*/

#include "my.h"

#include <unistd.h>
#include <errno.h>

int command_handle_arch_error(void *shell, int error)
{
    if (error != ENOEXEC)
        return 0;
    shell_set_code(shell, 1);
    return 1;
}
