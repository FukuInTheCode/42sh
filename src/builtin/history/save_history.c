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

static void write_in_file(shell_t *shell, int fd)
{
    history_t *to_free = NULL;

    if (fd == -1 || shell_get_history(shell) == NULL)
        return;
    for (history_t *tmp = shell_get_history(shell); tmp; tmp = tmp->next) {
        if (to_free) {
            free(to_free->line);
            free(to_free);
        }
        dprintf(fd, "#+%li\n%s\n", tmp->time, tmp->line);
        to_free = tmp;
    }
}

void save_history(shell_t *shell, char *file_name)
{
    history_t *current_history = copy_history(shell_get_history(shell));
    int fd;

    remove_history(shell);
    shell_set_history(shell, NULL);
    history_load_from_file(shell, file_name);
    for (history_t *tmp = copy_history(shell_get_history(shell));
    tmp; tmp = tmp->next) {
        add_in_history(shell, tmp->line);
        shell_get_history(shell)->time = tmp->time;
    }
    fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0600);
    for (history_t *tmp = current_history; tmp; tmp = tmp->next) {
        add_in_history(shell, tmp->line);
        shell_get_history(shell)->time = tmp->time;
    }
    write_in_file(shell, fd);
    close(fd);
}
