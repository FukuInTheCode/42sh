/*
** EPITECH PROJECT, 2024
** 42sh-mirror
** File description:
** dir_close_arg
*/
#include "autocompletion.h"
#include "my.h"
#include <stdio.h>
#include <stdlib.h>

static char **command_find_loop_in_dir(DIR *dir, char *arg, int **buffer_size)
{
    struct dirent *entry;
    char **buff = NULL;
    char *temp = NULL;

    entry = readdir(dir);
    buff = command_realloc(buff, buffer_size[0]);
    while (entry != NULL) {
        if (entry->d_name[0] != '.') {
            temp = is_directory_or_exec(entry->d_name, arg, arg);
            buff[(*buffer_size)[1]] = strdup(temp);
            buff[(*buffer_size)[1] + 1] = NULL;
            buff = command_realloc(buff, buffer_size[0]);
            (*buffer_size)[1]++;
        }
        entry = readdir(dir);
    }
    buff[(*buffer_size)[1]] = NULL;
    closedir(dir);
    return buff;
}

static void free_dir(char **good_arg, int *buffer_size)
{
    my_free_word_array(good_arg);
    free(buffer_size);
}

char **directory_close(char *arg)
{
    DIR *dir;
    char **buffer = NULL;
    int *bf = calloc(sizeof(int) * 2, sizeof(int) * 2);
    char **r = NULL;
    char **ga = my_str_to_word_array(arg, "/");

    dir = opendir(arg);
    if (dir == NULL) {
        free_dir(ga, bf);
        return NULL;
    }
    r = (strncmp(arg, "./", 2) == 0) ?
        command_find_loop_in_dir(dir, arg, &bf) :
        command_find_loop_in_dir(dir, ga[my_len_word_array(ga) - 1], &bf);
    if (r[0] == NULL) {
        my_free_word_array(r);
        return NULL;
    }
    free_dir(ga, bf);
    return allocation_of_buffer(buffer, r);
}
