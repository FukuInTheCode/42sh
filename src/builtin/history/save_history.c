/*
** EPITECH PROJECT, 2024
** 42sh-mirror
** File description:
** save_history.c
*/

#include "shell.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

static void write_history(history_t *history, int fd)
{
    if (history->next)
        write_history(history->next, fd);
    dprintf(fd, "#+%li\n%s", history->time, history->line);
}

void save_history(history_t *history, char **argv, int argc)
{
    int fd;

    if (argc != 3)
        return;
    fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0600);
    write_history(history, fd);
}
