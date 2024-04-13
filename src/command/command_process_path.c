/*
** EPITECH PROJECT, 2024
** command_process_path.c
** File description:
** command_process_path.c
*/

#include "my.h"

#include <stdlib.h>
#include <string.h>
#include "env.h"

static bool is_relative_path(char const *path)
{
    for (size_t i = 0; path[i]; i++)
        if (path[i] == '/')
            return true;
    return false;
}

static int handle_tmp(command_t *command, char *s, char *tmp)
{
    if (!tmp)
        return 1;
    strcat(tmp, s);
    if (s[strlen(s) - 1] != '/')
        strcat(tmp, "/");
    strcat(tmp, command->argv[0]);
    if (!access(tmp, F_OK | X_OK)) {
        command_set_path(command, tmp);
        free(tmp);
        return 1;
    }
    free(tmp);
    return 0;
}

static int get_path(command_t *command, char *path)
{
    char **arr = my_str_to_word_array(path, ":");
    char *tmp = NULL;

    if (!arr)
        return 84;
    for (size_t i = 0; arr[i]; i++) {
        if (arr[i][strlen(arr[i]) - 1] == '/')
            tmp = calloc(strlen(arr[i]) +
                strlen(command->argv[0]) + 1, sizeof(char));
        else
            tmp = calloc(strlen(arr[i]) +
                strlen(command->argv[0]) + 2, sizeof(char));
        if (handle_tmp(command, arr[i], tmp))
            break;
    }
    my_free_word_array(arr);
    if (!command_get_path(command))
        command_set_path(command, command->argv[0]);
    return 0;
}

int command_process_path(command_t *command, void *shell)
{
    char *path = env_get(shell_get_env(shell), "PATH");

    if (!path || is_relative_path(command->argv[0])) {
        command_set_path(command, command->argv[0]);
        return 0;
    }
    return get_path(command, path);
}
