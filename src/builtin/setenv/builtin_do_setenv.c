/*
** EPITECH PROJECT, 2024
** setenv.c
** File description:
** setenv.c
*/

#include "my.h"
#include "env.h"
#include "builtins.h"

static bool variable_name_is_good(char const *name, shell_t *shell)
{
    for (size_t i = 0; variables_errors[i].f; i++) {
        if (variables_errors[i].f(shell, name)) {
            dprintf(2, "setenv");
            error_put((void *)(variables_errors + i));
            return false;
        }
    }
    return true;
}

static bool setenv_argv_is_good(shell_t *shell, int argc, char **argv)
{
    if (argc > 3) {
        dprintf(2, "setenv: Too many arguments.\n");
        shell_set_code(shell, 1);
        return false;
    }
    if (!variable_name_is_good(argv[1], shell))
        return false;
    return true;
}

int builtin_do_setenv(command_t *command, shell_t *shell)
{
    int argc = command_get_argc(command);
    char **argv = command_get_argv(command);

    if (argc == 1)
        return builtin_do_printenv(command, shell);
    if (!setenv_argv_is_good(shell, argc, argv))
        return 0;
    if (env_get(shell_get_env(shell), argv[1])) {
        shell_set_env(shell, env_change(shell->env, argv[1], argv[2]));
        shell_set_code(shell, 0);
        return 0;
    }
    shell_set_env(shell, env_add(shell->env, argv[1], argv[2]));
    shell_set_code(shell, 0);
    return 0;
}
