/*
** EPITECH PROJECT, 2024
** builtin_do_where.c
** File description:
** builtin_do_where.c
*/

#include "builtins.h"
#include "env.h"
#include "my.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

static bool get_bin_path(char *path, char *path_bin, char *argv)
{
    int flag = 0;

    for (; path != NULL; path = strtok(NULL, ":")) {
        path_bin = malloc(strlen(path) + strlen(argv) + 2);
        if (!path_bin)
            return 84;
        sprintf(path_bin, "%s/%s", path, argv);
        if (access(path_bin, X_OK) != 0) {
            free(path_bin);
            continue;
        }
        printf("%s\n", path_bin);
        free(path_bin);
        flag += 1;
    }
    if (flag >= 1)
        return true;
    return false;
}

static int display_builtin_do_where(shell_t *shell, char **argv)
{
    char *all_path;
    char *path;
    char *path_bin = NULL;
    bool found = false;

    for (int i = 1; argv[i] != NULL; i++) {
        if (display_where_with_invalid_caract(argv[i], shell))
            found = true;
        all_path = strdup(env_get(shell->env, "PATH"));
        path = strtok(all_path, ":");
        found = false;
        if (display_where_builtin(argv[i]))
            found = true;
        if (get_bin_path(path, path_bin, argv[i]))
            found = true;
        display_where_command_not_found(found, shell);
        free(all_path);
    }
    return 0;
}

static int where_with_no_argc(shell_t *shell)
{
    dprintf(2, "where: Too few arguments.\n");
    shell_set_code(shell, 1);
    return 0;
}

int builtin_do_where(command_t *command, shell_t *shell)
{
    int argc = 0;
    char **argv = NULL;

    if (command == NULL || shell == NULL)
        return 84;
    argc = command_get_argc(command);
    argv = command_get_argv(command);
    if (argc == 1)
        return where_with_no_argc(shell);
    return display_builtin_do_where(shell, argv);
}
