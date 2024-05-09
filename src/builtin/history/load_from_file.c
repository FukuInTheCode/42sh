/*
** EPITECH PROJECT, 2024
** 42sh-mirror
** File description:
** load_from_file.c
*/

#include "shell.h"
#include "history.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int is_number(char *buffer)
{
    if (strlen(buffer) > 3 && buffer[0] == '#' && buffer[1] == '+')
        return 1;
    else
        return 0;
}

static long int get_time(char *buffer)
{
    int size = strlen(buffer);
    char *time_in_str;
    long int time;

    if (size < 3)
        return -1;
    time_in_str = calloc(strlen(buffer) - 2, sizeof(char));
    for (int i = 0; buffer[i + 2]; i++)
        time_in_str[i] = buffer[i + 2];
    time = atol(time_in_str);
    free(time_in_str);
    return time;
}

static void parse_file(shell_t *shell, FILE *file)
{
    char *buffer = NULL;
    size_t n = 0;
    long int time;

    for (int size = 0; getline(&buffer, &n, file) != -1 && buffer
    && size < 100; size++) {
        if (!is_number(buffer))
            continue;
        time = get_time(buffer);
        if (getline(&buffer, &n, file) == -1 || !buffer) {
            free(buffer);
            return;
        }
        if (buffer[0] != '\n') {
            buffer[strlen(buffer) - 1] = 0;
            add_in_history(shell, buffer);
            shell_get_history(shell)->time = time;
        }
    }
    free(buffer);
}

void history_load_from_file(shell_t *shell, char *file_name)
{
    FILE *file;

    file = fopen(file_name, "r");
    if (file == NULL)
        return;
    parse_file(shell, file);
    fclose(file);
}
