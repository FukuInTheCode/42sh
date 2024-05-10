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
#include "string.h"

static void free_search(int *buffer_size, char **pas)
{
    free(buffer_size);
    if (pas)
        my_free_word_array(pas);
}

static char **buffer_dir(char *arg)
{
    char **buffer = NULL;

    if (strchr(arg, '/') != NULL) {
        buffer = directory_close(arg);
        return buffer;
    } else
        return NULL;
}

static bool loop_search(DIR **dir, char *pas, int **buffer_size)
{
    reset_variables(dir, pas, buffer_size);
    if (*dir == NULL)
        return true;
    else
        return false;
}

static bool are_there_free(int *buffer_size, char **pas)
{
    if (!pas || !buffer_size) {
        free_search(buffer_size, pas);
        return true;
    }
    return false;
}

char *is_directory_or_exec(char *name, char *path, char *arg)
{
    struct stat file_stat;
    char *temp = malloc(sizeof(char) * strlen(path) + strlen(name) + 2);

    strcpy(temp, path);
    temp = strcat(temp, "/");
    temp = strcat(temp, name);
    if (stat(temp, &file_stat) == -1) {
        free(temp);
        return name;
    }
    if (S_ISDIR(file_stat.st_mode))
        name = strcat(name, "/");
    if (access(temp, X_OK) != -1 && !S_ISDIR(file_stat.st_mode)
        && find_space(arg) == 1)
        name = strcat(name, "*");
    free(temp);
    return name;
}

char **buffer_add(char **buff, char *temp, int **buffer_size)
{
    buff[(*buffer_size)[1]] = strdup(temp);
    buff[(*buffer_size)[1] + 1] = NULL;
    buff = command_realloc(buff, buffer_size[0]);
    (*buffer_size)[1]++;
    return buff;
}

char **command_find_loop(DIR *dir, char *arg, int **buffer_size, char *path)
{
    struct dirent *entry;
    char **str = my_str_to_word_array(arg, "/");
    char **buff = NULL;
    char *temp = NULL;

    entry = readdir(dir);
    buff = command_realloc(buff, buffer_size[0]);
    while (entry != NULL) {
        if (strncmp(entry->d_name, str[my_len_word_array(str) - 1],
            strlen(str[my_len_word_array(str) - 1])) == 0
            && entry->d_name[0] != '.') {
            temp = is_directory_or_exec(entry->d_name, path, arg);
            buff = buffer_add(buff, temp, buffer_size);
        }
        entry = readdir(dir);
    }
    buff[(*buffer_size)[1]] = NULL;
    my_free_word_array(str);
    closedir(dir);
    return buff;
}

char **search_command(char *arg, shell_t *sh)
{
    DIR *dir = NULL;
    char **pas = path_handle(arg, sh);
    int *buffer_size = calloc(sizeof(int) * 2, sizeof(int) * 2);
    char **result = NULL;
    char **buffer = buffer_dir(arg);

    if (are_there_free(buffer_size, pas))
        return NULL;
    for (int i = 0; pas[i] != NULL; i++) {
        if (loop_search(&dir, pas[i], &buffer_size) == true)
            continue;
        result = command_find_loop(dir, arg, &buffer_size, pas[i]);
        if (result == NULL || result[0] == NULL) {
            my_free_word_array(result);
            continue;
        }
        buffer = allocation_of_buffer(buffer, result);
    }
    free_search(buffer_size, pas);
    return buffer;
}
