/*
** EPITECH PROJECT, 2024
** search_command
** File description:
** search_command
*/

#include "autocompletion.h"
#include "my.h"
#include <dirent.h>
#include <stdlib.h>

static char **command_realloc(int buffer_count,
    char **buffer, int *buffer_size)
{
    if (buffer_count >= *buffer_size) {
        *buffer_size += 10;
        buffer = realloc(buffer, sizeof(char *) * (*buffer_size));
        if (buffer == NULL)
            perror("realloc");
    }
    return buffer;
}

char **command_find_loop(DIR *dir, char *arg,
    int *buffer_count, int *buffer_size)
{
    struct dirent *entry;
    char **buffer = NULL;

    entry = readdir(dir);
    while (entry != NULL) {
        if (strncmp(entry->d_name, arg, strlen(arg)) == 0) {
            buffer = command_realloc(*buffer_count, buffer, buffer_size);
            buffer[*buffer_count] = strdup(entry->d_name);
            (*buffer_count)++;
        }
        entry = readdir(dir);
    }
    buffer[*buffer_count] = NULL;
    return buffer;
}

char **search_command(char *arg)
{
    DIR *dir;
    char **buffer = NULL;
    int buffer_size = 0;
    int buffer_count = 0;

    dir = opendir("/usr/bin");
    if (dir == NULL)
        perror("opendir");
    buffer = command_find_loop(dir, arg, &buffer_count, &buffer_size);
    closedir(dir);
    return buffer;
}
