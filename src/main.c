/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main.c
*/

#include "my.h"

#include "env.h"
/*
int main(int argc, char **argv, char **envp)
{
    shell_t *shell = NULL;
    int code = 0;

    if (argc != 1 || !argv)
        return 84;
    shell = shell_create();
    shell_set_env(shell, env_copy(envp));
    if (shell_run(shell) == 84) {
        shell_destroy(shell);
        return 84;
    }
    code = shell_get_code(shell);
    shell_destroy(shell);
    return code;
}
*/