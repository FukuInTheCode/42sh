/*
** EPITECH PROJECT, 2024
** builtin_unsetenv.c
** File description:
** builtin_unsetenv.c
*/

#include "my.h"
#include "env.h"

int builtin_do_unsetenv(command_t *command, shell_t *shell)
{
    char **tmp_env = NULL;
    char **argv = command_get_argv(command);
    int argc = command_get_argc(command);

    if (argc == 1) {
        dprintf(2, "unsetenv: Too few arguments.\n");
        shell_set_code(shell, 1);
        return 0;
    }
    for (size_t i = 1; argv[i]; i++)
        if (env_get(shell->env, argv[i]))
            tmp_env = env_remove(shell_get_env(shell), argv[i]);
    if (tmp_env)
        shell_set_env(shell, tmp_env);
    shell_set_code(shell, 0);
    return 0;
}
