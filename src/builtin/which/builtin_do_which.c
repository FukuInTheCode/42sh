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

bool get_bin_path(char *path, bool found, char *path_bin, char *argv)
{
    for (; path != NULL && found != true; path = strtok(NULL, ":")) {
        path_bin = malloc(strlen(path) + strlen(argv) + 2);
        sprintf(path_bin, "%s/%s", path, argv);
        if (access(path_bin, X_OK) != 0)
            continue;
        printf("%s\n", path_bin);
        found = true;
        free(path_bin);
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
        display_which_command_not_found(argv[i], found, shell);
        free(all_path);
    }
    return 0;
}

static int which_with_no_argc(shell_t *shell)
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
        return which_with_no_argc(shell);
    return display_builtin_do_which(shell, argv);
}
