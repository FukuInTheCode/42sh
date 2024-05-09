/*
** EPITECH PROJECT, 2024
** 42sh-mirror
** File description:
** save_history.c
*/

#include "shell.h"
#include "history.h"

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

static void write_in_file(history_t *history, int fd)
{
    if (fd == -1 || !history)
        return;
    write_in_file(history->next, fd);
    dprintf(fd, "#+%li\n%s\n", history->time, history->line);
    free(history->line);
    free(history);
    history = NULL;
}

void save_history(shell_t *shell, char *file_name)
{
    history_t *current_history = copy_history(shell_get_history(shell));
    int fd;

    remove_history(shell);
    history_load_from_file(shell, file_name);
    while (current_history->next)
        current_history = current_history->next;
    for (; current_history->prev; current_history = current_history->prev) {
        add_in_history(shell, current_history->line);
        shell_get_history(shell)->time = current_history->time;
    }
    add_in_history(shell, current_history->line);
    shell_get_history(shell)->time = current_history->time;
    fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0600);
    write_in_file(shell_get_history(shell), fd);
    if (fd == -1)
        remove_history(shell);
    else
        close(fd);
    shell_set_history(shell, current_history);
}
