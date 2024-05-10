/*
** EPITECH PROJECT, 2024
** builtin_do_which.c
** File description:
** builtin_do_which.c
*/

#include "builtins.h"
#include "env.h"
#include "my.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "sys/stat.h"

static bool get_bin_path(char *path, bool found, char *path_bin, char *argv)
{
    for (; path != NULL && found != true; path = strtok(NULL, ":")) {
        path_bin = malloc(strlen(path) + strlen(argv) + 2);
        if (!path_bin)
            return false;
        sprintf(path_bin, "%s/%s", path, argv);
        if (access(path_bin, X_OK) != 0) {
            free(path_bin);
            continue;
        }
        printf("%s\n", path_bin);
        found = true;
        free(path_bin);
        return true;
    }
    return false;
}

static bool get_bin_inside_current_directory(char *argv)
{
    struct stat info_file;

    if (stat(argv, &info_file) == -1)
        return false;
    if (access(argv, X_OK) == 0 && !(S_ISDIR(info_file.st_mode))) {
        printf("%s\n", argv);
        return true;
    }
    return false;
}

static int display_builtin_do_which(shell_t *shell, char **argv)
{
    char *all_path;
    char *path;
    char *path_bin = NULL;
    bool found = false;

    for (int i = 1; argv[i] != NULL; i++) {
        all_path = strdup(env_get(shell->env, "PATH"));
        path = strtok(all_path, ":");
        found = false;
        if (display_which_builtin(argv[i]))
            found = true;
        if (get_bin_path(path, found, path_bin, argv[i]))
            found = true;
        if (get_bin_inside_current_directory(argv[i]))
            found = true;
        display_which_command_not_found(argv[i], found, shell);
        free(all_path);
    }
    free(path_bin);
    return 0;
}

static int do_which_with_no_argc(shell_t *shell)
{
    dprintf(2, "which: Too few arguments.\n");
    shell_set_code(shell, 1);
    return 0;
}

int builtin_do_which(command_t *command, shell_t *shell)
{
    int argc = 0;
    char **argv = NULL;

    if (command == NULL || shell == NULL)
        return 84;
    argc = command_get_argc(command);
    argv = command_get_argv(command);
    if (argc == 1)
        return do_which_with_no_argc(shell);
    return display_builtin_do_which(shell, argv);
}
