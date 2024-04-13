/*
** EPITECH PROJECT, 2024
** builtin_cd.c
** File description:
** builtin_cd.c
*/

#include "my.h"
#include "env.h"
#include "builtins.h"

#include "string.h"
#include <errno.h>
#include <stdlib.h>

static bool cd_args_is_good(shell_t *shell, int argc)
{
    if (argc > 2) {
        shell_set_code(shell, 1);
        dprintf(2, "cd: Too many arguments.\n");
        return false;
    }
    return true;
}

static int cd_change_wd(shell_t *shell, char const *new_pwd)
{
    char *pwd = getcwd(NULL, 0);

    if (!pwd)
        return 84;
    if (chdir(new_pwd) == -1)
        builtin_handle_cd_errors(shell, pwd, errno);
    free(pwd);
    pwd = getcwd(NULL, 0);
    shell_set_env(shell, env_change(shell->env, "PWD", pwd));
    free(pwd);
    return 0;
}

int builtin_do_cd(command_t *command, shell_t *shell)
{
    int argc = command_get_argc(command);
    char **argv = command_get_argv(command);

    if (!cd_args_is_good(shell, argc))
        return 0;
    if (argc == 1 || !strncmp(argv[1], "~", 2))
        return cd_change_wd(shell, env_get(shell->env, "HOME"));
    if (!strncmp(argv[1], "-", 2))
        return cd_change_wd(shell, env_get(shell->env, "OLDPWD"));
    return cd_change_wd(shell, argv[1]);
}
