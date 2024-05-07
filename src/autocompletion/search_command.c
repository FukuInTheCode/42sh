/*
** EPITECH PROJECT, 2024
** search_command
** File description:
** search_command
*/

#include "autocompletion.h"
#include "my.h"
#include "env.h"
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>

static char **command_realloc(char **buffer, int *buffer_size)
{
    char **temp = my_copy_word_array(buffer);

    if (buffer == NULL)
        *buffer_size = 0;
    else {
        *buffer_size = my_len_word_array(buffer);
    }
    temp = realloc(temp, sizeof(char *) * (*buffer_size + 2));
    if (temp == NULL)
        perror("realloc");
    my_free_word_array(buffer);
    return temp;
}

char *is_directory_or_exec(char *name, char *path, char *arg)
{
    struct stat file_stat;
    char *temp = malloc(sizeof(char) * strlen(path) + strlen(name) + 2);

    strcpy(temp, path);
    temp = strcat(temp, "/");
    temp = strcat(temp, name);
    if (stat(temp, &file_stat) == -1)
        return name;
    if (S_ISDIR(file_stat.st_mode))
        name = strcat(name, "/");
    if (access(temp, X_OK) != -1 && !S_ISDIR(file_stat.st_mode)
        && find_space(arg) == 1)
        name = strcat(name, "*");
    free(temp);
    return name;
}

char **command_find_loop(DIR *dir, char *arg, int **buffer_size, char *path)
{
    struct dirent *entry;
    char **buff = NULL;
    char *temp = NULL;

    entry = readdir(dir);
    buff = command_realloc(buff, buffer_size[0]);
    while (entry != NULL) {
        if (strncmp(entry->d_name, arg, strlen(arg)) == 0
            && entry->d_name[0] != '.') {
            temp = is_directory_or_exec(entry->d_name, path, arg);
            buff[(*buffer_size)[1]] = strdup(temp);
            buff[(*buffer_size)[1] + 1] = NULL;
            buff = command_realloc(buff, buffer_size[0]);
            (*buffer_size)[1]++;
        }
        entry = readdir(dir);
    }
    buff[(*buffer_size)[1]] = NULL;
    return buff;
}

void reset_variables(DIR **dir, char *path, int **buffer_size)
{
    (*buffer_size)[0] = 0;
    (*buffer_size)[1] = 0;
    (*dir) = opendir(path);
}

static char **allocation_of_buffer(char **buffer, char **result)
{
    char **temp = my_copy_word_array(buffer);

    if (temp == NULL) {
        temp = malloc(sizeof(char *) * ((my_len_word_array(result) + 1)));
        temp = memset(temp, 0, sizeof(char *)
            * ((my_len_word_array(result) + 1)));
    }
    temp = my_cat_word_array(temp, result);
    my_free_word_array(buffer);
    return temp;
}

char **search_command(char *arg, shell_t *sh)
{
    DIR *dir;
    char **buffer = NULL;
    char **pas = path_handle(arg, sh);
    int *buffer_size = calloc(sizeof(int) * 2, sizeof(int) * 2);
    char **result = NULL;

    buffer_size[1] = 0;
    for (int i = 0; pas[i] != NULL; i++) {
        reset_variables(&dir, pas[i], &buffer_size);
        if (dir == NULL)
            continue;
        result = command_find_loop(dir, arg, &buffer_size, pas[i]);
        closedir(dir);
        if (result[0] == NULL) {
            my_free_word_array(result);
            continue;
        }
        buffer = allocation_of_buffer(buffer, result);
        my_free_word_array(result);
    }
    free(buffer_size);
    my_free_word_array(pas);
    return buffer;
}
