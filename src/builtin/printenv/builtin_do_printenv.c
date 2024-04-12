/*
** EPITECH PROJECT, 2024
** builtin_env.c
** File description:
** builtin_env.c
*/

#include "my.h"

int builtin_do_printenv(command_t *command, shell_t *shell)
{
    int argc = command_get_argc(command);

    if (argc != 1) {
        shell_set_code(shell, 1);
        return 0;
    }
    for (size_t i = 0; shell->env[i]; i++)
        printf("%s\n", shell->env[i]);
    shell_set_code(shell, 0);
    return 0;
}
