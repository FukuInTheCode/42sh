/*
** EPITECH PROJECT, 2024
** shell_init_variable.c
** File description:
** shell_init_variable.c
*/

#include "shell.h"
#include "builtins.h"
#include "env.h"


int shell_init_variable(shell_t *shell)
{
    add_linked_list_set("home", env_get(shell->env, "HOME"), shell);
    add_linked_list_set("path", env_get(shell->env, "PATH"), shell);
    add_linked_list_set("shlvl", env_get(shell->env, "SHLVL"), shell);
    return 0;
}
