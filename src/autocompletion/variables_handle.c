/*
** EPITECH PROJECT, 2024
** 42sh-mirror
** File description:
** variables_handle
*/

#include "autocompletion.h"
#include "my.h"
#include "env.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *save_copy(char *temp_save, char *save, char **temp, int i)
{
    strcpy(temp_save, save);
    strcat(temp_save, " ");
    strcat(temp_save, temp[i]);
    free(save);
    save = temp_save;
    return save;
}

char *save_handle(char **temp)
{
    char *save = strdup(temp[0]);
    char *temp_save = NULL;

    if (save == NULL)
        return NULL;
    if (my_len_word_array(temp) == 1) {
        free(save);
        return NULL;
    }
    if (temp[1] == NULL)
        return save;
    for (size_t i = 1; i < my_len_word_array(temp) - 1; i++) {
        temp_save = malloc(strlen(save) + strlen(temp[i]) + 2);
        if (temp_save == NULL) {
            free(save);
            return NULL;
        }
        save = save_copy(temp_save, save, temp, i);
    }
    return save;
}

static void free_path(char *last_arg_path,
    char **temp, char *full_path, char *result)
{
    my_free_word_array(temp);
    free(full_path);
    free(result);
    free(last_arg_path);
}

static char *concatenate_path(char *last_arg_path,
    char *arg, char *result, char *full_path)
{
    result = strdup(full_path);
    result = realloc(result, strlen(full_path) + strlen(":.") + 1);
    strcat(result, ":.");
    strncpy(last_arg_path, arg, strlen(arg));
    last_arg_path[strlen(arg)] = '\0';
    result = realloc(result, strlen(full_path) + strlen(last_arg_path) + 8);
    strcat(result, ":./");
    strcat(result, last_arg_path);
    return result;
}

char **path_handle(char *arg, shell_t *shell)
{
    char **temp = my_str_to_word_array(arg, " ");
    char **send = NULL;
    char *save = env_get(shell_get_env(shell), "PATH");
    char *full_path = NULL;
    char *result = NULL;
    char *last_arg_path = malloc(strlen(arg) + 1);

    if (!save) {
        free(last_arg_path);
        return NULL;
    }
    if (last_arg_path == NULL) {
        perror("Allocation error");
        return NULL;
    }
    full_path = strdup(save);
    result = concatenate_path(last_arg_path, arg, result, full_path);
    send = my_str_to_word_array(result, ":");
    free_path(last_arg_path, temp, full_path, result);
    return send;
}

char *modify_arg(char *arg)
{
    char **temp = my_str_to_word_array(arg, "/");
    char *result = strdup(temp[my_len_word_array(temp) - 1]);

    if (arg[strlen(arg) - 1] == '/') {
        my_free_word_array(temp);
        return " ";
    }
    my_free_word_array(temp);
    return result;
}

void reset_variables(DIR **dir, char *path, int **buffer_size)
{
    (*buffer_size)[0] = 0;
    (*buffer_size)[1] = 0;
    (*dir) = opendir(path);
}
