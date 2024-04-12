/*
** EPITECH PROJECT, 2024
** command_handle_left_red.c
** File description:
** command_handle_left_red.c
*/

#include "my.h"

#include <errno.h>
#include <fcntl.h>

static int handle_errors(command_t *right, int error)
{
    char const *file_name = command_get_argv(command_get_next(right))[0];

    if (error == EACCES) {
        dprintf(2, "%s : Permission denied.\n", file_name);
        return 0;
    }
    if (error == ENOENT) {
        dprintf(2, "%s : No such file or directory.\n", file_name);
        return 0;
    }
    return 0;
}

int command_handle_left_red(command_t *command, command_t *left, void *shell)
{
    int fd = 0;

    if (!shell || !left || !command)
        return 84;
    fd = open(command_get_argv(command_get_next(left))[0], O_RDONLY);
    if (fd < 0) {
        handle_errors(left, errno);
        return 84;
    }
    command_set_in(command, fd);
    return 0;
}
