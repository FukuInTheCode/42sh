/*
** EPITECH PROJECT, 2024
** command_handle_double_left_red.c
** File description:
** command_handle_double_left_red.c
*/

#include "my.h"

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int add_input(char ***inputs, char const *input)
{
    size_t len = my_len_word_array(*inputs);

    *inputs = realloc(*inputs, (len + 2) * sizeof(char *));
    if (!*inputs)
        return 84;
    (*inputs)[len] = strdup(input);
    (*inputs)[len + 1] = NULL;
    return 0;
}

static char **handle_eof(char const *eof)
{
    char **inputs = calloc(1, sizeof(char *));
    size_t len = 0;
    char *line = 0;

    if (!inputs)
        return NULL;
    for (; getline(&line, &len, stdin) != -1;) {
        if (line[strlen(line) - 1] == '\n')
            line[strlen(line) - 1] = 0;
        if (!strcmp(line, eof))
            break;
        add_input(&inputs, line);
    }
    return inputs;
}

int command_handle_double_left_red(command_t *command,
    command_t *left, void *shell)
{
    int fds[2] = {0};
    char **inputs = NULL;

    if (!shell || !command || !left)
        return 84;
    if (pipe(fds))
        return 84;
    command_set_in(command, fds[0]);
    inputs = handle_eof(command_get_argv(command_get_next(left))[0]);
    for (size_t i = 0; inputs[i]; i++) {
        dprintf(fds[1], "%s\n", inputs[i]);
    }
    my_free_word_array(inputs);
    close(fds[1]);
    return 0;
}
